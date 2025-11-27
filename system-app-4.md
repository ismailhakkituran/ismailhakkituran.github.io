Shell Uygulamaları - 27
========================

# Shell’de Değişken Tanımlama

```bash
#!/bin/bash

# değişken adı = değer (boşluk yok!)
name="Ahmet"
age=25

echo "İsim: $name"
echo "Yaş: $age"
```

* Bash değişkenleri **tip içermez** (integer, string aynı şekilde tutulur)
* `=` işaretinin etrafında **boşluk olamaz**

---

# Matematiksel İşlemler

## Yöntem 1 — `$(( ))` aritmetik genişleme

```bash
a=10
b=3

echo $((a + b))
echo $((a - b))
echo $((a * b))
echo $((a / b))     
echo $((a % b))    
```

## Yöntem 2 — `expr`

```bash
expr 5 + 3
```

## Yöntem 3 — Ondalıklı işlem (bc)

```bash
echo "scale=4; 10 / 3" | bc
echo "scale=8; 10 / 3" | bc
```

---

# if - else Yapısı

```bash
#!/bin/bash

x=15

if [ $x -gt 10 ]; then
    echo "x 10'dan büyük"
elif [ $x -eq 10 ]; then
    echo "x eşit 10"
else
    echo "x 10'dan küçük"
fi
```

### Karşılaştırma Operatörleri

| Operatör | Anlam           |
| -------- | --------------- |
| `-eq`    | eşit            |
| `-ne`    | eşit değil      |
| `-gt`    | büyük           |
| `-lt`    | küçük           |
| `-ge`    | büyük veya eşit |
| `-le`    | küçük veya eşit |

---

# while Döngüsü

```bash
#!/bin/bash

i=1

while [ $i -le 5 ]; do
    echo "Sayı: $i"
    i=$((i+1))
done
```

---

# for Döngüsü

## Liste üzerinde döngü

```bash
for fruit in apple banana cherry; do
    echo "Meyve: $fruit"
done
```

## C tarzı döngü

```bash
for ((i=1; i<=5; i++)); do
    echo "i = $i"
done
```

## Dosya listesi üzerinde döngü

```bash
for file in *.txt; do
    echo "Bulunan: $file"
done
```

---

# `find` Komutu Örneği

## Bir dizindeki tüm `.txt` dosyalarını bul:

```bash
find /home/user -type f -name "*.txt"
```

## Son 7 günde değiştirilmiş `.log` dosyaları:

```bash
find /var/log -type f -name "*.log" -mtime -7
```

## Boyutu 10MB üzeri dosyalar:

```bash
find /home -type f -size +10M
```

## Bulunan dosyaları silme (çok dikkatli!)

```bash
find /tmp -type f -name "*.tmp" -delete
```

---

# Sütun Kesme Örnekleri (cut, awk)

## `/etc/passwd` dosyasından kullanıcı adını al

```bash
cut -d: -f1 /etc/passwd
```

## CPU kullanımı en yüksek 3 prosesin PID’lerini çek

---

# “En çok CPU kullanan 3 process’in PID değerini veriniz”

### `ps + head + awk`

```bash
ps -eo pid,%cpu --sort=-%cpu | head -n 4 | awk 'NR>1 {print $1}'
```

Açıklama:

* `ps -eo pid,%cpu` → PID ve CPU sütunlarını listele
* `--sort=-%cpu` → CPU’ya göre büyükten küçüğe sırala
* `head -n 4` → ilk satır başlık, sonraki 3 satır proses
* `awk 'NR>1 {print $1}'` → başlığı at, PID sütununu yaz

### Örnek çıktı:

```
1234
998
456
```

---

### `top`’tan veri çekerek

```bash
top -b -n1 | grep -E "^[ ]*[0-9]" | sort -k9 -nr | head -n3 | awk '{print $1}'
```

`top -b -n1`
* şu anlama gelir:
* top’u batch mode çalıştır
* tek seferlik snapshot üret
* çıktıyı terminale bas ve çık

---

### Tamamını tek bir script olarak:

```bash
#!/bin/bash

echo "En çok CPU kullanan 3 proses PID:"
ps -eo pid,%cpu --sort=-%cpu | head -n 4 | awk 'NR>1 {print $1}'
```

---

# En çok CPU kullanan 3 programın isimlerini göster

```bash
ps -eo comm,%cpu --sort=-%cpu | head -n 4 | awk 'NR>1 {print $1}'
```



---

# `grep` ile REGEX Kullanımı

Temel kullanım:

```bash
grep "pattern" dosya.txt
```

Regex’i aktif etmek için:

* `grep -E` → Extended regex
* `grep -P` → Perl regex (en güçlü)
* `grep -r` → recursive search

---

# Temel grep Regex Örnekleri

## Satır içindeki kelimeyi bul

```bash
grep "error" log.txt
```

## Belirli bir kelimeyle başlayan satırları bul (^)

```bash
grep "^root" /etc/passwd
```

## Belirli bir kelime ile biten satırlar ($)

```bash
grep "bash$" /etc/passwd
```

## Sadece sayısal içeren satırlar

```bash
grep "^[0-9]*$" dosya.txt
```

## Bir karakter grubunu eşleştirme []

### İçinde a, b veya c olan satır:

```bash
grep "[abc]" dosya.txt
```

### Sadece rakam olan satırlar:

```bash
grep "^[0-9]+$" dosya.txt
```

---

# Extended Regex (grep -E)

## Alternasyon (OR) — |

```bash
grep -E "error|warning" log.txt
```

## Tekrarlama — +, ?, {n} 
+ en az 1 kere
? sıfır veya 1 kere


```bash
grep -E "file[0-9]+\.txt" dosya_listesi.txt
echo "logs" | grep -E "log?s"
echo "colour" | grep -E "colou?r"
echo "color"  | grep -E "colou?r"
echo "caaat" | grep -E "a+"
echo "abc123def" | grep -E "[0-9]+"
echo "abc1234" | grep -E "[0-9]{3}"

```

## Sadece harflerden oluşan satırlar

```bash
grep -E "^[a-zA-Z]+$" file.txt
```

---

# Perl Regex (grep -P)

## E-posta tespiti

```bash
grep -P "[\w.-]+@[\w.-]+\.\w+" users.txt
```

## Non-greedy (lazy) match

```bash
grep -P "<title>.*?</title>" index.html
```

---

# Recursive grep (klasör içi tarama)

```bash
grep -R "main()" src/
```

---

# Shell’de Wildcard ile Regex'in Farkı

### Önemli: **Shell pattern’leri (globbing) regex değildir**

Aşağıdakiler **regex değildir**, **shell pattern** (wildcard) ifadesidir:

* `*` → sıfır veya daha fazla karakter
* `?` → tek karakter
* `[]` → karakter grubu

Örneğin:

```
ls z*
```

Bu bir **regex değil**, "z ile başlayan dosyaları listeler" demektir.

---

# Örnekler — Shell Pattern vs Regex

## `ls z*`

Z ile başlayan tüm dosyalar:

* `z`
* `zoom`
* `zebra.txt`
* `zzzz`

---

## `ls *.txt`

`.txt` ile biten tüm dosyalar

---

## `ls ?a*`

İkinci karakteri “a” olan tüm dosyalar:

* `ba.txt`
* `ha.log`
* `xa123`

---

## `ls [abc]*`

**a, b veya c ile başlayan** dosyalar

---

# Shell Wildcard → grep Regex’e Nasıl Çevrilir?

| Shell Pattern | Anlamı             | Grep Regex Karşılığı |
| ------------- | ------------------ | -------------------- |
| `z*`          | z ile başlayan     | `^z.*`               |
| `*.txt`       | .txt ile biten     | `\.txt$`             |
| `?a*`         | ikinci karakter a  | `^.a.*`              |
| `[abc]*`      | a,b,c ile başlayan | `^[abc].*`           |

Örnek:

```bash
grep "^z" dosya_listesi.txt
```

---

# grep + regex ile pratik örnekler

## URL satırlarını bul

```bash
grep -E "https?://[a-zA-Z0-9./_-]+" web.log
```

## IPv4 adresi bul

```bash
grep -E "([0-9]{1,3}\.){3}[0-9]{1,3}" network.log
```

## Yorum satırlarını (# ile başlayan) ele

```bash
grep "^#" script.sh
```

---

# En çok CPU kullanan 3 prosesin PID'ini regex ile çek (ps + grep değil ama AWK regex kullanıyor)

```bash
ps aux | awk '$3 ~ /^[0-9.]+$/ {print $2,$3}' | sort -k2 -nr | head -n3
```

---





## **Komut çalıştırma (command substitution)** operatörü

Yani:

```
result=`komut`
```

Şeklinde, bir komutun çıktısını değişkene atar.

Ancak **aritmetik işlem için de dolaylı olarak kullanılabilir**, çünkü `expr` komutu ile birlikte sıkça görülür:

---

# Backtick ile aritmetik işlem yapma (eski yöntem)

```bash
x=5
y=3

z=`expr $x + $y`
echo $z
```

Burada:

* `` `expr $x + $y` `` → önce expr çalışır
* Çıkışı `z` değişkenine atanır

Bu yöntem **eski** ama hâlâ çalışır.

---

# Aynısının modern karşılığı → `$(( ))` (önerilen)

```bash
z=$((x + y))
```

Bu hem hızlı hem modern.

---

# Backtick’in modern alternatifi → `$( )`

Backtick yerine genelde **$( )** kullanılır:

```bash
z=$(expr $x + $y)
```

Daha okunaklıdır.

---

| Yazım                | Açıklama                                 |
| -------------------- | ---------------------------------------- |
| `` `expr $a + $b` `` | Eski stil aritmetik                      |
| `$(expr $a + $b)`    | Modern komut çalıştırma                  |
| `$((a + b))`         | Bash aritmetik operatörü (tercih edilen) |

---

# Neden üç farklı yöntem var?

### 1) `expr` + backtick ⇒ *Eski Unix geleneği*

### 2) `$( )` ⇒ *POSIX modern command substitution*

### 3) `$(( ))` ⇒ *Bash'in gerçek aritmetik operatörü (kod daha temiz)*

---

# ÖNERİLEN (modern, doğru, sade):

```bash
x=10
y=20
z=$((x + y))
echo $z
```

---
