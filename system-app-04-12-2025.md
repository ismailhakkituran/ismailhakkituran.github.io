Aşağıda belirttiğin başlıkları **laboratuvar uygulaması gibi**, hem *öğretici açıklamalar* hem de *çalıştırılabilir örneklerle* hazırladım.
Bu içerik **System Programming – Hafta 1–2** kapsamında doğrudan kullanılabilir.

---

# 🟦 **1. Shell komutlarını beraber ve peş peşe çalıştırma**

## ✔️ 1.1. Ardışık (peş peşe) komut çalıştırma

Komutlar sırayla çalışır; biri bitmeden diğeri başlamaz.

### `;` operatörü

```bash
ls ; pwd ; whoami
```

Sırası:

1. `ls`
2. `pwd`
3. `whoami`

Komut başarısız olsa da sıradaki çalışır.

---

## ✔️ 1.2. Şarta bağlı çalışma

### `&&` → önceki komut başarılıysa çalışır

### `||` → önceki komut başarısızsa çalışır

Örnek:

```bash
mkdir test && echo "Klasör oluşturuldu"
```

`mkdir` başarılıysa echo çalışır.

```bash
cd not_exist || echo "Klasör yok"
```

---

## ✔️ 1.3. Paralel komut çalıştırma `&`

Tek komut arka planda:

```bash
firefox &
```

Birden fazla komut paralel:

```bash
sleep 5 & sleep 7 & sleep 10 &
```

Terminali meşgul etmeden 3 komut aynı anda yürür.

---

---

# 🟦 **2. `$0` parametresi ile recursive script çalıştırma**

`$0` **scriptin kendi adıdır** — böylece script kendini tekrar çağırabilir.

### Örnek: Kendini N kez çağıran recursive script

```bash
#!/usr/bin/bash

count=$1
echo "Call: $count"

if [ "$count" -lt 5 ]; then
    next=$((count + 1))
    bash "$0" "$next"
fi
```

Çalıştır:

```bash
./recursive.sh 1
```

Sonuç:

```
Call: 1
Call: 2
Call: 3
Call: 4
Call: 5
```

---

---

# 🟦 **3. Terminal cihazlarını listeleme**

Linux’ta terminal aygıtları `/dev` altında bulunur.

## ✔️ Tüm terminalleri listeleme

```bash
ls -l /dev/tty*
```

## ✔️ Mevcut terminal cihazını öğrenme

```bash
tty
```

Örnek çıktı:

```
/dev/pts/1
```

---

---

# 🟦 **4. USB cihazlarını listeleme**

USB aygıtları sistemde kernel tarafından enumerate edilir.

### ✔️ lsusb

```bash
lsusb
```

Örnek:

```
Bus 001 Device 005: ID 046d:c52b Logitech Unifying Receiver
```

### ✔️ Daha detaylı USB bilgileri

```bash
lsusb -v
```

### ✔️ Hangi dosya sistemine mount edilmiş?

```bash
df -h | grep /media
```

### ✔️ Kernel log ile USB takibini görmek

```bash
dmesg | tail -n 20
```

USB tak/çıkar anında doğrudan kernel mesajı verir.

---

---

# 🟦 **5. Diski listeleyen komutlar ve fraksiyonlar**

## ✔️ Dolu/boş alanları gösterme

```bash
df -h
```

* `-h` → human readable (GB/MB)

Örnek çıktı:

```
Filesystem      Size  Used Avail Use% Mounted on
/dev/sda1       100G   50G   50G  50% /
```

### Sadece belli bir disk aygıtını görmek:

```bash
df -h /home
```

---

## ✔️ Disk blok seviyesinde inceleme

```bash
lsblk
```

Örnek:

```
sda     8:0    0 465G  0 disk
├─sda1  8:1    0 450G  0 part /
└─sda2  8:2    0  15G  0 part swap
```

---

---

# 🟦 **6. RAM bilgisi ve bellek fraksiyonları**

Linux’ta RAM ve swap kullanımını gösteren birkaç komut vardır:

---

## ✔️ free komutu

```bash
free -h
```

Örnek:

```
              total        used        free      shared  buff/cache   available
Mem:           15Gi       3.1Gi        8Gi       232Mi       3.5Gi        12Gi
Swap:         2.0Gi       0.0Gi        2.0Gi
```

---

## ✔️ /proc/meminfo dosyasını okumak

```bash
cat /proc/meminfo
```

Örnek:

```
MemTotal:       16339772 kB
MemFree:         8097236 kB
Buffers:          125480 kB
Cached:          3123456 kB
```

---

## ✔️ RAM detayını gösteren `ls` fraksiyonları?

Senin kastettiğin muhtemelen **ls ile dosya RAM kullanımı** değil, diske göre boyutlandırma.

Ama “ls fraksiyonları” deyince genelde:

* `ls -l` → uzun liste
* `ls -lh` → insan okunur boyut
* `ls -s` → dosyanın kapladığı blok miktarı
* `ls -sh` → insan okunur blok
* `ls -alh` → gizli dosyaları da göster, insan okunur

Örnek:

```bash
ls -alh /var/log
```

---

# 🟩 Eğer RAM kullanımını process bazlı listelemek istersen:

```bash
ps aux --sort=-%mem | head
```

veya grafiksel:

```bash
top
```

---

# İstersen buradan bir **Uygulama Laboratuvarı** (.md formatında) çıkarabilirim:

* Ardışık komutlar
* Paralel (background) komutlar
* `$0` ile recursive script
* USB, disk, terminal cihazlarının keşfi
* RAM/Disk inceleme
* Process izleme

Ders notu olarak hazır hale getirebilirim. İster misin?
