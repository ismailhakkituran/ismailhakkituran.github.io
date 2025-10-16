# 🗓️ Hafta 1: Linux Sistemi Tanıma ve Shell’e Giriş
**Tema:** “Linux dünyasında bir programın doğduğu yer: Shell”

## 🎯 Amaçlar
- Öğrencinin Linux/Unix ekosistemine zihinsel olarak adapte olması  
- Dosya sistemi hiyerarşisini anlaması  
- Shell’in sistemle nasıl konuştuğunu kavraması  
- Basit komut zincirleriyle giriş/çıkış yönlendirme mantığını kavraması  

---

## 📘 1. Giriş: Neden Linux?
- “Sistem Programlama” neden Linux üzerinde anlatılır?  
- Kernel vs User-space  
- Shell’in rolü (örnek: `ls` yazınca kernel seviyesinde neler olur)  
- CLI ile GUI farkı (script edilebilirlik, deterministik davranış, otomasyon)

---

## 📂 2. Linux Dosya Sistemi Hiyerarşisi
Bir sistemcinin ezbere bilmesi gereken dizinlerin özeti:

| Dizin | Açıklama |
|-------|-----------|
| `/` | Root dizini, her şeyin başlangıcı |
| `/bin` | Temel kullanıcı komutları (`ls`, `cat`, `cp`) |
| `/sbin` | Sistem yönetim komutları (`ifconfig`, `mount`) |
| `/usr` | Kullanıcı programları ve kütüphaneleri |
| `/lib` | Paylaşılan kütüphaneler |
| `/etc` | Sistem yapılandırma dosyaları |
| `/dev` | Donanım aygıt dosyaları (`/dev/tty`, `/dev/null`) |
| `/proc` | Sanal dosya sistemi: sistem bilgisi (`cat /proc/cpuinfo`) |
| `/tmp` | Geçici dosyalar |
| `/var` | Loglar, spool dosyaları |
| `/home` | Kullanıcıların ev dizinleri |

🧠 *Mini tartışma:*  
> “Bir komutun sistemin neresinden çalıştığını anlamak için hangi yolları izleriz?”  
Cevap: `$PATH` değişkeni, `which`, `whereis`

---

## 💻 3. Shell ile Temel Etkileşim

### 3.1 Shell türleri
- `sh`, `bash`, `zsh`, `dash` farkı  
- Bash prompt yapısı: `PS1`, `$USER`, `$PWD`  

### 3.2 Temel Komutlar
| Komut | Açıklama |
|--------|-----------|
| `pwd`, `ls`, `cd`, `mkdir`, `rmdir` | Dizin işlemleri |
| `cat`, `head`, `tail`, `less`, `grep` | Dosya görüntüleme ve arama |
| `cp`, `mv`, `rm`, `touch` | Dosya yönetimi |
| `echo`, `date`, `whoami`, `uname -a` | Bilgi komutları |
| `man`, `--help` | Dokümantasyon |

### 3.3 Girdi/Çıktı ve Yönlendirme
- `>` : stdout yönlendirme  
- `>>` : append  
- `<` : stdin yönlendirme  
- `|` : pipe  
- `2>` : stderr yönlendirme  
- `tee` : hem dosyaya hem ekrana yazma  

💡 *Gösteri:*  
```bash
ls /bin | grep sh | tee shell_list.txt
```

---

## 🧩 4. Ortam Değişkenleri ve PATH
```bash
echo $PATH
export MYNAME="Ismail"
echo "Benim adım $MYNAME"
```
- `env`, `printenv`  
- `.bashrc` ve `.profile` farkı  
- `$HOME`, `$PWD`, `$USER`, `$SHELL`  

---

## ⚙️ 5. Sistem Süreçlerine Kısa Bakış
- `ps aux`, `top`, `htop`  
- `kill`, `killall`, `sleep`, `jobs`, `fg`, `bg`  
- Arka plan kavramı: `&`  

---

## 🧠 6. Bash Script Temelleri
```bash
#!/bin/bash
echo "Merhaba $(whoami), bugün $(date)"
```
- `chmod +x hello.sh`  
- `./hello.sh`  
- `$0`, `$1`, `$#`, `$@` argüman kullanımı  

---

## 🧪 Hafta 1 Mini-Lab: “Ben Kimim?” Scripti
**Amaç:** Öğrencinin ortam değişkenleri, yönlendirmeler ve basit script yazımını öğrenmesi  

**Görev:**  
`whoami.sh` isminde bir bash script yaz:  
1. Kullanıcının adını (`$USER`) ve ev dizinini yazsın.  
2. Sistemin tarihini ve uptime değerini yazsın.  
3. Bu bilgileri `log.txt` adlı bir dosyaya kaydetsin ve aynı zamanda ekrana yazsın (`tee` ile).  
4. Script dosyasının çalıştırılabilir olmasını sağla.  

**Örnek çıktı:**  
```
Kullanıcı: ismail
Ev dizini: /home/ismail
Tarih: Thu Oct 16 01:05:04 +03 2025
Sistem: up 2 hours, 15 minutes
```

---

## 📚 Ek Okuma / Kaynak
- **“The Linux Command Line”** – William Shotts (1–4. Bölümler)  
- `man hier` → Linux dizin yapısı açıklaması  
- `tldr` → Modern komut örnekleri (öner: `sudo apt install tldr`)  

---

## 🎓 Sonraki Hafta İçin Hazırlık
> System çağrıları (fork, exec, wait) temellerine giriş —  
> "Bir shell nasıl yeni bir process başlatır?"
