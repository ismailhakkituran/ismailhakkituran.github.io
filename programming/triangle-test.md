Çizilebilir Üçgen Testi (Üçgen Eşitsizliği)
===============================================
## Amaç

Kullanıcıdan **3 adet uzunluk** değeri alıp bu üç uzunlukla **geometrik olarak bir üçgen çizilip çizilemeyeceğini** kontrol eden bir program yazınız.
Program, üçgen çizilebiliyorsa **`1`**, çizilemiyorsa **`0`** yazdırmalıdır.

## Tanım

Bir üçgenin çizilebilmesi için (üçgen eşitsizliği):

* Tüm kenarlar **pozitif** olmalı.
* Her bir kenar, **diğer iki kenarın toplamından küçük** olmalı.

Yani (a, b, c > 0) ve

* (a + b > c)
* (a + c > b)
* (b + c > a)

şartları sağlanmalıdır.

## Girdi / Çıktı Biçimi

* **Girdi:** Kullanıcıdan üç uzunluk değeri (tam sayı veya ondalık) alınacaktır.
  (Sırasıyla `a`, `b`, `c` değerleri)
* **Çıktı:** Sadece **tek bir satır**da **`1`** veya **`0`** yazdırınız.


> Not: Uzunluklar sıfır veya negatif verilirse üçgen çizilemez ve çıktı **`0`** olmalıdır.

## Örnekler

**Örnek 1**

Girdi: `3 4 5`
Çıktı: `1`  (çünkü 3+4>5, 3+5>4, 4+5>3)

**Örnek 2**

Girdi: `1 2 3`
Çıktı: `0`  (1+2=3 olduğu için eşitlik durumunda üçgen oluşmaz)

**Örnek 3**

Girdi: `2.5 4 1.6`
Çıktı: `1`

**Örnek 4**

Girdi: `0 5 5`
Çıktı: `0`  (pozitif değil)

**Örnek 5**

Girdi: `-2 4 5`
Çıktı: `0`  (pozitif değil)

## Değerlendirme Kriterleri

* **Doğruluk (70%)**: Tüm kuralları doğru uygulayıp doğru sonucu üretmesi.
* **Kod Kalitesi (30%)**: Anlaşılır değişken adları, gerekli yorum satırları, gereksiz tekrarların olmaması.

## Ödev Teslimi

* https://toy.emrecan.dev/ sayfasında çalışan uygulamanızı kodlayıp bir editöre yapıştırınız.
* Dosya ismi **öğrenci numaranız**, dosya uzantısı **tm** (Örnek dosya adı 2524005.tm )
* Bir text dosyasının uzantısı nasıl değiştirilir araştırınız.
* Formata uygun teslim edilmeyen ödevler değerlendirilmeyecektir.
* Bu ödevde, son uygulamada anlatılan github vs. kullanılmayacaktır.
