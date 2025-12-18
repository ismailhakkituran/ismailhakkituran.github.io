Çalışmamız **ESP32 tabanlı CSI (Channel State Information) ile İç Mekan Konumlandırma** üzerine odaklanıyor. Tasarladığınız senaryo (mobil terminalde 4 ESP32 ile 4 köşedeki AP'yi dinlemek), alıcı tarafında (Rx) uzamsal çeşitliliği (spatial diversity) artırarak "Device-Based" (Cihaz Tabanlı) konumlandırmada yüksek hassasiyet potansiyeli taşımaktadır.


### 1. İlgili Çalışmaların Özeti ve Listesi

*   **Macedo vd.:** Çalışma, iç mekanlarda cihazsız (pasif) konumlandırma için sabit konumlara yerleştirilmiş **4 adet ESP32** alıcısı ve bir Erişim Noktası (AP) kullanmıştır. Sinyal işleme hattı (gürültü giderme, segmentasyon) ve **Random Forest (Rastgele Orman)** sınıflandırıcısı kullanılarak, gerçek bir laboratuvar ortamında 43 farklı ızgara noktası için **%82'nin üzerinde doğruluk** elde edilmiştir. Bu çalışma, düşük maliyetli donanımlarla (ESP32) CSI tabanlı konumlandırmanın uygulanabilirliğini kanıtlaması açısından senaryomuza en yakın örneklerden biridir.
*   **Pandey vd.,,:** Karantina ortamlarında ortak konum ve aktivite takibi için **ESP32** tabanlı düşük maliyetli bir donanım tasarlanmıştır. **Siamese Ağı (1-D CNN ve Bi-LSTM)** mimarisi kullanılarak, kişinin konumu **0.32 metre** hata payı ile tahmin edilmiş ve aktivite tanımada %99 başarı sağlanmıştır.
*   **Zeeshan vd.,:** Yine **ESP32** kullanılarak cihazsız ortak aktivite ve konumlandırma üzerine çalışılmıştır. **Siamese ağları** ve "contrastive loss" fonksiyonu kullanılarak, özellikle eğitim setinde görülmeyen ortamlar için genelleme yeteneği artırılmış; konumlandırmada **%99 doğruluk** oranına ulaşılmıştır. Veri artırma (data augmentation) ve ikili örnekleme (pairwise sampling) teknikleri kullanılmıştır.
*   **Sun vd.,:** Çoklu AP (4 adet) kullanılan bir NLOS (görüş hattı olmayan) ortamda, CSI genliği ve faz farkından oluşturulan **CSI görüntüleri** kullanılmıştır. **2D DCNN (Derin Evrişimli Sinir Ağı)** modeli ve olasılık tabanlı bir koordinat hesaplama algoritması ile simülasyon ortamında (QuaDRiGa) **0.676 metre** ortalama hata ile konumlandırma yapılmıştır.
*   **Kai vd.,:** Akıllı ev ortamında **ESP32 CSI Toolkit** kullanılarak alıcı-verici yerleşim desenleri incelenmiştir. Aktivite tahmini için **SVM**, oda seviyesinde konumlandırma (hangi odada olduğu) için **LightGBM** kullanılmış ve 4 bağlantılı (link) senaryoda oda tahmininde **%91 doğruluk** elde edilmiştir.
*   **Nagia vd.,:** **Federated Learning (Federe Öğrenme)** mimarisi ile **CNN ve LSTM** modelleri kullanılarak, veri gizliliğini koruyan bir işbirlikçi konumlandırma sistemi önerilmiştir. **ASUS RT-AC86U (Nexmon)** donanımı ile toplanan verilerde, merkezi modele kıyasla daha düşük iletişim yükü ile **1-2 metre** aralığında hata payı elde edilmiştir.
*   **Zhang vd.,:** Belirsizlikler altındaki cihazsız konumlandırma için **Variance-Constrained Local-Global Modeling** (Varyans Kısıtlı Yerel-Küresel Modelleme) önerilmiştir. **ELM (Extreme Learning Machine)** tabanlı bu yöntem, verileri istatistiksel özelliklerine göre kümelere ayırarak (clustering) modellemiş ve **Intel 5300** kartları ile yapılan deneylerde, ortam değişimlerine karşı gürbüz (robust) sonuçlar vermiştir.
*   **Li vd.:** Termal (Sıcaklık) kaynakların yerini tespit etmek için **ESP32** ve **SVM** sınıflandırıcısı kullanılmıştır. Isı değişiminin CSI genliği üzerindeki etkisini analiz ederek, ısı kaynağının konumunu **%99 doğrulukla** tahmin etmişlerdir. Bu çalışma, ESP32'nin hassas değişimleri algılamadaki başarısını göstermektedir.
**Wi-CaL: Simultaneous Crowd Counting and Localization**
    *   **Teknik:** ESP32 modülleri (Tx ve Rx olarak) kullanılarak 52 alt taşıyıcıdan CSI genlik verileri toplanmış, makine öğrenmesi (SVM, Random Forest, LGBM) ile eğitilmiştir.
    *   **Senaryo:** 5.5m x 5.5m ve 11m x 5.5m boyutlarında iki farklı odada, 10 kişiye kadar kalabalık senaryosu.
    *   **Başarı:** Lokalizasyon doğruluğu %91.4 ile %98.1 arasında değişmiştir.
    *   **Önemi:** Sizin projeniz gibi ESP32 donanımını temel alır ve bu donanımın lokalizasyon için yeterli olduğunu kanıtlar.
**ConFi: CNN Based Indoor Wi-Fi Localization**
    *   **Teknik:** CSI verilerini zaman ve frekans boyutunda bir matris (CSI image) haline getirip 5 katmanlı bir CNN ile sınıflandırma problemi olarak çözer.
    *   **Senaryo:** Laboratuvar ve koridor ortamında tek bir AP kullanılarak yapılan testler.
    *   **Başarı:** RSSI tabanlı yöntemlere (Horus, RADAR) göre %40-60 oranında hata azaltımı sağlamıştır.
    *   **Önemi:** CSI verisini "eğitip" konum tahmini yapma kurgunuz için en güçlü mimari referansıdır.
**TIPS: Transformer Based Indoor Positioning System**
    *   **Teknik:** CSI ve DoA (Direction of Arrival) verilerini birleştirip, Transformer (NLP'de kullanılan mimari) tabanlı bir model ile eğitmiştir.
    *   **Senaryo:** USRP (Universal Software Radio Peripheral) kullanılarak toplanan verilerle, karmaşık bir iç mekan senaryosu.
    *   **Başarı:** 20 cm hata payı içinde %100 doğruluk (simülasyon ve kontrollü ortamda).
    *   **Önemi:** Derginin "Industrial Informatics" olması sebebiyle, CNN/LSTM ötesinde Transformer gibi modern mimarilerin kullanıldığını göstermek için iyi bir kıyaslamadır.

---

*   **ESP32 ve Donanım Temelli Referanslar:**
    *   **Wi-CaL:** ESP32 modüllerini kullanarak WiFi CSI ile kalabalık sayma ve lokalizasyon yapan en güncel ve ilgili çalışmalardan biridir. ESP32 CSI toolkit kullanımı ve 52 alt taşıyıcı (subcarrier) verisinin işlenmesi konusunda doğrudan referansınızdır.
    *   **WIFI CSI-BASED LONG-RANGE...:** ESP32-S3 kullanarak uzun menzilli lokalizasyon yapılmıştır. ESP32'nin CSI toplama yeteneklerini ve donanım kısıtlarını (PIFA anten vs.) tartışmak için kullanmalısınız.

*   **Yöntem (Fingerprinting & Deep Learning) Referansları:**
    *   **ConFi:** CSI verisini bir "görüntü" (CSI feature image) gibi işleyip CNN (Convolutional Neural Network) kullanan öncü çalışmadır. Sizin de CSI verisini eğitmeniz gerekeceği için bu yöntem temel bir karşılaştırma noktasıdır.
    *   **DeepFi:** CSI genlik verilerini kullanarak derin öğrenme (Autoencoder) ile fingerprinting yapan temel çalışmadır. RSSI yerine CSI'ın kararlılığını savunan hipotezleri.
    *   **A CNN-LSTM Quantifier...:** Tek bir AP ile CNN ve LSTM (Long Short-Term Memory) kullanarak konumlandırma yapar. Sizin 4 AP senaryonuzun, bu çalışmadaki tek AP kısıtını nasıl aştığını tartışmak için önemlidir. Ayrıca bu çalışma ESP32'nin pasif lokalizasyon potansiyelinden bahsetmektedir.

*   **Veri İşleme ve Gürültü Azaltma:**
    *   **Wi-Tar:** CSI verisindeki gürültüyü azaltmak ve donanım kaynaklı faz hatalarını gidermek için "CSI Ratio" (CSI Oranı) yöntemini kullanır. 4 ESP32 arasındaki faz/genlik farklarını kullanacaksanız bu referans kritiktir.
    *   **Device-Free Localization Based on CSI Fingerprints...:** Ham CSI verilerini temizlemek için DBSCAN ve boyut indirgemek için PCA (Principal Component Analysis) kullanımını önerir. Veri ön işleme bölümünde tartışılabilir

---
**A. İç Mekan Konumlandırmada CSI ve RSSI Karşılaştırması**
Geleneksel iç mekan konumlandırma sistemleri çoğunlukla Alınan Sinyal Gücü Göstergesi (RSSI) üzerine kuruludur,. Ancak RSSI, çok yollu sönümleme (multipath fading) ve gölgeleme etkileri nedeniyle kararsızlık gösterebilmekte ve hassas konumlandırma için yetersiz kalabilmektedir,. Buna karşılık, Kanal Durum Bilgisi (CSI), fiziksel katmanda (PHY) her bir alt taşıyıcı (subcarrier) için genlik ve faz bilgisi sağlayarak, ortamın çok daha ayrıntılı bir "parmak izini" sunar,. Araştırmalar, CSI tabanlı yöntemlerin, özellikle dinamik ve karmaşık endüstriyel ortamlarda RSSI'a göre üstün performans sergilediğini göstermektedir,.

**B. Düşük Maliyetli IoT Donanımları ile CSI Algılama**
CSI verilerinin elde edilmesi geçmişte Intel 5300 veya Atheros gibi özel Ağ Arayüz Kartları (NIC) gerektirirken,, Nesnelerin İnterneti (IoT) cihazlarının gelişimi ile bu durum değişmiştir. Özellikle Espressif **ESP32** mikrodenetleyicileri, düşük maliyetleri ve güç verimlilikleri ile CSI tabanlı algılama için popüler bir platform haline gelmiştir,. Hernandez ve Bulut tarafından geliştirilen ESP32 CSI Toolkit, bu alandaki çalışmaları hızlandırmıştır. Literatürde, ESP32 kullanılarak yapılan çalışmalar genellikle insan aktivitesi tanıma (HAR), düşme tespiti ve cihazsız (pasif) konumlandırma, üzerine yoğunlaşmıştır. Örneğin, Macedo vd., sabit ESP32 alıcıları ile %82 üzerinde konumlandırma doğruluğu elde etmiştir. Ancak, mobil terminal üzerinde çoklu ESP32 kullanarak MIMO benzeri bir yapı ile "cihaz tabanlı" (device-based) hassas konumlandırma üzerine yapılan çalışmalar sınırlıdır.

**C. Konumlandırma Algoritmaları ve Derin Öğrenme**
CSI verilerinin yüksek boyutu ve karmaşıklığı, gelişmiş işleme tekniklerini zorunlu kılmaktadır. Deterministik yöntemler (ör. kNN, SVM) ve olasılıksal yöntemler (ör. Horus) yaygın olarak kullanılsa da, son yıllarda Derin Öğrenme (DL) yaklaşımları öne çıkmaktadır. Wang vd. ve Sun vd., CSI genlik ve faz verilerini görüntüye dönüştürerek 2D-CNN modelleri ile özellik çıkarımı yapmış ve metre altı doğruluklar elde etmişlerdir. Ayrıca, zaman serisi verilerindeki zamansal bağımlılıkları yakalamak için LSTM ve Bi-LSTM yapıları, özellikle aktivite ve konumun eş zamanlı takibinde (Joint Localization and Activity Recognition) başarıyla uygulanmıştır,.

**D. Mevcut Çalışmalardaki Boşluklar ve Önerilen Yaklaşım**
Mevcut literatürde ESP32 kullanımı genellikle tekil bağlantılar veya sabit alıcı ağları ile sınırlıdır. Endüstriyel bilişim uygulamalarında, mobil robotlar veya operatörler üzerindeki terminallerin hassas takibi kritiktir. Bu çalışma, mobil terminal üzerine entegre edilmiş **4 adet ESP32** modülü ile alıcı tarafında uzamsal çeşitliliği (spatial diversity) artırarak ve gelişmiş DL/ML modelleri kullanarak, düşük maliyetli donanımlarla yüksek hassasiyetli bir iç mekan konumlandırma sistemi önermektedir. Bu yaklaşım, pahalı FPGA veya SDR tabanlı sistemlere ekonomik ve ölçeklenebilir bir alternatif sunmaktadır.

---

### 3. Kıyaslama Tablosu

**Table 1. Comparison of CSI-Based Indoor Localization and Sensing Systems**

| Reference | Hardware Platform | Mode & Configuration | Algorithm / Model | Feature Extraction | Performance / Accuracy |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Macedo et al. (2025)** | 4 $\times$ ESP32 (Anchors) + 1 $\times$ AP | Device-Free (Passive); 4 Fixed Receivers | Random Forest (Dual-stage & Unified) | Statistical features (Mean, Std Dev) of CSI Magnitude | Accuracy: >82% (43 grid points) |
| **Pandey et al. (2023)** | ESP32 | Device-Free; Single Link (Tx-Rx) | Siamese Network (1D-CNN + Bi-LSTM) | Raw CSI Amp. + Phase (Denoised) | Localization Error: 0.32m; HAR Accuracy: 99.7% |
| **Sun et al. (2022)** | Simulation (QuaDRiGa) | Device-Based; 4 Tx - 1 Rx | 2D DCNN + Probability-based calc. | CSI Images (Amp. + Phase Diff.) | Mean Error: 0.676m (NLOS environment) |
| **Nagia et al. (2023)** | ASUS RT-AC86U (Nexmon) | Device-Based; 5 APs (Monitor Mode) | Federated Learning (CNN + MLP) | CSI Images (Amp. + Phase Diff.) | Median Error: ~1.5m |
| **Zhang et al. (2023)** | Intel 5300 NIC | Device-Free; 1 Tx - 1 Rx | Variance-Constrained Local-Global ELM | Clustering + ELM Kernel Space | Superior robustness in cluttered environments |
| **Kai et al. (2023)** | ESP32 | Device-Free; Up to 5 nodes (4 links) | SVM (Activity) + LightGBM (Loc.) | Statistical features of Amplitude | Room Estimation Acc.: ~91% (4-link) |
| **Li et al. (2021)** | ESP32 | Thermal Sensing; 2 Tx - 2 Rx | Support Vector Machine (SVM) | Subcarrier Selection + Windowing | Source Localization Acc.: ~99% |


| Reference | Hardware Platform | Signal Feature | Algorithm / Model | Localization Type | Accuracy / Error |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **DeepFi** | Intel 5300 NIC | CSI Amplitude | SAE (Stacked Autoencoder) | Fingerprinting | ~0.95 m (Mean Error) |
| **ConFi** | Intel 5300 NIC | CSI Image (Time-Freq) | CNN (5-Layer) | Fingerprinting | ~1.37 m (Mean Error) |
| **CSI-MIMO** | Intel 5300 NIC | CSI Amp. & Phase | k-NN & Bayes | Fingerprinting | 0.98 m (Static) |
| **Wi-CaL** | **ESP32** | CSI Amplitude | SVM / LGBM | Classification (Zone) | 98.1% (Accuracy) |
| **TIPS** | USRP (Software Radio) | CSI + DoA | **Transformer** | Regression | < 0.5 m (90% CDF) |
| **CNN-LSTM** | Intel 5300 | CSI Amplitude | CNN + LSTM | Regression | 2.5 m (Single AP) |
| **Zhou et al.** | Intel 5300 | CSI Amplitude | DNN + PCA + DBSCAN | Regression | 1.08 m (Mean Error) |


**Tablo Notları:**
*   **Mode:** *Device-Free* (Hedef cihaz taşımaz, ortamdaki değişim izlenir) vs. *Device-Based* (Hedef cihaz taşır, sinyal kaynağı veya alıcısıdır).
*   **MIMO-like:** Mobil terminaldeki 4 ESP32, 4 antenli bir alıcı gibi davranarak uzamsal çeşitliliği artırır, bu da endüstriyel ortamlardaki sönümleme (fading) etkilerini azaltmak için güçlü bir yöntemdir.


**Intel 5300 CSI Tool** ve **ESP32 CSI Tool** arasındaki alt-taşıyıcı (subcarrier) kıyaslaması aşağıdadır:

**1. Intel 5300 CSI Tool:**
*   **Alt-Taşıyıcı Sayısı:** Intel 5300 NIC donanımı ve ilgili CSI aracı, genellikle **30 adet alt-taşıyıcı** grubu raporlar,,.
*   **Çalışma Prensibi:** IEEE 802.11n standardında 20 MHz bant genişliği için aslında 56, 40 MHz bant genişliği için 114 alt-taşıyıcı bulunmasına rağmen, Intel 5300 sürücüsü bu verileri "gruplayarak" dışarı aktarır,. Örneğin, 20 MHz bant genişliğinde yaklaşık her iki alt-taşıyıcıdan biri (veya bir grup) raporlanarak toplamda 30 veri noktası elde edilir.
*   **Kısıt:** Bu durum, mevcut tüm alt-taşıyıcılara erişilememesi nedeniyle bir kısıtlama olarak kabul edilir.

**2. ESP32 CSI Tool:**
*   **Alt-Taşıyıcı Sayısı:** ESP32 modülleri (Espressif ESP32) kullanılarak yapılan ölçümlerde, 20 MHz bant genişliği (HT20) için **52 adet alt-taşıyıcıdan** CSI verisi elde edilebilmektedir,.
*   **Çalışma Prensibi:** ESP32, 2.4 GHz WiFi bandında çalışırken boş (null) olmayan 52 alt-taşıyıcının tamamına erişim sağlayabilir.
*   **Avantajı:** Intel 5300'ün sağladığı 30 alt-taşıyıcıya kıyasla, ESP32 aynı bant genişliğinde (20 MHz) daha fazla sayıda alt-taşıyıcı verisi sunarak frekans alanında daha yüksek bir çözünürlük sağlar.

**Özet Kıyaslama Tablosu:**

| Özellik | Intel 5300 CSI Tool | ESP32 CSI Tool |
| :--- | :--- | :--- |
| **Raporlanan Alt-Taşıyıcı Sayısı** | **30**, | **52**, |
| **Veri Granülaritesi** | Düşük (Veriler gruplanarak verilir) | Yüksek (Daha fazla alt-taşıyıcı erişimi) |
| **Bant Genişliği** | 20 MHz / 40 MHz (Ancak çıktı hep 30'dur) | 20 MHz (HT20 modunda test edilmiştir) |

Sonuç olarak, **ESP32 CSI Tool**, Intel 5300'e göre 20 MHz bandında daha fazla sayıda alt-taşıyıcı (52 vs 30) sağlayarak, ortamdaki değişimleri frekans alanında daha detaylı yakalama potansiyeline sahiptir.
