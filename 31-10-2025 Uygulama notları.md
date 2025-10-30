31/10/2025 Programlamaya Giriş Uygulamalası
===========================================

# Terminale Giriş

Windows ve Linux/Unix türevi işletim sistemleri diskte farklı otururlar. Windows diskte tanımladığı sürücü biriminden itibaren başlayaral hiyerarşik olarak oturur. Windows' un kendi sistemi ve uygulamaları genellikle `C` sürücünde oturur. Harici olarak sisteme bağlanan her eleman yeni bir sürücü adıyla sisteme tanımlanır. `D`, `F`, `E`, `G`...vb.

Linux/Unix sistemler ise `/` (root ters duran bir ağacın en üstü olan kökü anlamında) dizininden itibaren oturur. `cd /` ve ardından listeleme `ls` yaparak listelenen klasörleri inceleyiniz. Bu sistemlerde, her disk (sistemin üzerinde oturduğu disk de dahil) `mnt` (mount) klasörü altında tanımlanmaktadır. Harici olarak bağlanan her saklama elemanı da mount edildikten sonra burada görünmektedir. (Windowsta `D`, `E`, `F`... idi)

Aynı disk üzerinde 2 sistem kullanmaktayız. O halde wsl terminali kullanarak Windows' un masaüstüne ulaşmaya çalışalım.

Masaüstü klasörünün Windowstaki adresi:

`C:\Users\<kullanıcı adı>\Desktop`

`C:\Users\<kullanıcı adı>\onedrive\Desktop` (bulut yedekleme açık ise)
şeklindedir.

Biz aynı masaüstüne Linux/Unix sistem bakış açısı ile:

`/mnt/c/Users/<kullanıcı adı>/Desktop`

şeklide ulaşabiliriz.

`touch` dosya oluşturma komutu ile terminalden, Windows' un masaüstüne birkaç dosya oluşturalım.

`touch deneme.txt`

`touch ilk_ruby_uygulamam.rb`

Bu dosyalara birşeyler yazıp kaydediniz. Şimdi standart çıkışa birşeyler yazan ve standart girişten birşeyler okuyan `ruby` uygulamanızı kodlayınız.

`echo "OMU" | ruby uygulama1.rb` komutundaki **stdout** ve **stdin** ' in nasıl yönlendirildiğini pekiştiriniz.

# Github hesabı oluşturma

bil.omu' lü hesabınızla github' a üye olunuz. Kullanıcı adınızın isim-soyisim kendisi veya kısaltması tavsiye edilmektedir. Örneğin: Recai OKTAŞ -> roktas

Bu hesabınızla google-classroomda paylaşılan ödevi kabul edip, listeden kendinizi seçiniz. Hesabınıza yüklenen ödevin açıklamasını dikkatle okuyunuz.
