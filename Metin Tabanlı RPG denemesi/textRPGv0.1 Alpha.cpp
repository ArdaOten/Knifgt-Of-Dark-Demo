#include <iostream>
#include <windows.h>
#include <string>
#include <fstream> // dosya okuma yazma için save/load
#include <ctime>   // Zaman kütüphanesi
#include <cstdlib> // rand ve srand için

using namespace std;

struct KarakterData{
    string karakter_adi = "Bilinmiyor";
    int secilisac;
    int kiloboysec,karakterkilosu=0,karakterboyu=0,kryas=0;
    int karaktercinsMenu=0;
    int can=100;
    int level =1;
    int xp=0;
    int xpbilgi=0;
    int toplamxp=0;
};
struct Buff {
    int kalanVurus = 0;
    float hasarCarpan = 1.0f;
    bool aktif = false;
};
enum class SilahTipi{Kilic=1, Balta, Yay};
struct Silah{
    string isim;
    int hasar = 0;
    SilahTipi tip;
};
struct KarakterItemData{
    int combatsans=0;
    int caniskir = 5;
    int saldirIkiKati=5;
    Buff gucBuff;
    int KilicSecme;
    Silah aktifSilah;
};
struct CanavarData{
    int canavaricani=0;
    int canavarhasar;
    string CanavarAdi;
};
enum class Cinsiyet{Erkek=1,Kiz,Cinsiyetsiz};
enum class SacRengi{Sari=1,Siyah,Kahverengi,Beyaz,Bos};

string SacRengiToString(SacRengi sac) {
    switch(sac) {
        case SacRengi::Sari: return "Sarı";
        case SacRengi::Siyah: return "Siyah";
        case SacRengi::Kahverengi: return "Kahverengi";
        case SacRengi::Beyaz: return "Beyaz";
    }
    return "Bilinmiyor";
};
string CinsiyetToString(Cinsiyet krcinsiyet) {
    switch(krcinsiyet) {
        case Cinsiyet::Erkek: return "Erkek";
        case Cinsiyet::Kiz: return "Kız";
    }
    return "Bilinmiyor";
};

class KarakterOzellestirme{
    private:
    int secim;
    SacRengi sac = SacRengi::Bos;
    Cinsiyet krcinsiyet =  Cinsiyet::Cinsiyetsiz;
    
    public:
    bool hatatespit = true;
     void KarakterSac(KarakterData &data){ 
        system("cls");
        cout << "      ****************************"<< endl;
        cout << "      ****Savaşcı Özelleştirme****"<< endl;
        cout << "      ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<< endl;
        cout << "      [1] Sarı"<< endl;
        cout << "      [2] Siyah"<< endl;
        cout << "      [3] Kahverengi"<< endl;
        cout << "      [4] Beyaz"<< endl;
        cout << "      [5] Çıkış"<< endl;
        cout << "      [*] Lütfen Saç Rengi Seçiniz!"<< endl;
        cout << "      >>>";
        cin >> data.secilisac;
        switch (data.secilisac){
        case 1:
        sac = SacRengi::Sari; break;
        case 2: 
        sac = SacRengi::Siyah; break;
        case 3:
        sac = SacRengi::Kahverengi; break;
        case 4:
        sac = SacRengi::Beyaz; break;
        case 5:
        break;
        default: 
        break;}
    }
     void KarakterBoyKilo(KarakterData &data){
               do{
        system("cls");
        cout << "      ****************************"<< endl;
        cout << "      ****Savaşcı Özelleştirme****"<< endl;
        cout << "      ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<< endl;
        cout << "      [1] Boy"<< endl;
        cout << "      [2] Kilo"<< endl;
        cout << "      [3] Çıkış"<< endl;
        cout << "      [*] Lütfen Savaşcıcınız'ın Boy Veya Kilosunu Ayarlayınız!"<< endl;
        cout << "      >>>";
        cin >> data.kiloboysec;
        switch(data.kiloboysec){
        case 1:
        system("cls");
        cout << "      ********************************"<< endl;
        cout << "      ****Savaşcı Boy Özelleştirme****"<< endl;
        cout << "      ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<< endl;
        cout << "      [*] Lütfen Savaşcıcınız'ın Boyunuzu Yazınız!"<< endl;
        cout << "      >>>";
        cin >> data.karakterboyu;
        break;
        case 2:
        system("cls");
        cout << "      *********************************"<< endl;
        cout << "      ****Savaşcı Kilo Özelleştirme****"<< endl;
        cout << "      ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<< endl;
        cout << "      [*] Lütfen Savaşcıcınız'ın Boyunuzu Yazınız!"<< endl;
        cout << "      >>>";
        cin >> data.karakterkilosu;
        break;
        }
        }while(data.kiloboysec!=3);
        }
     void KarakterCinVyaş(KarakterData &data){
            do{
        system("cls");

        cout << "      *************************************"<< endl;
        cout << "      ****Savaşcı Cinsiyet Özelleştirme****"<< endl;
        cout << "      ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<< endl;
        cout << "      [1] Erkek"<< endl;
        cout << "      [2] Kız"<< endl;
        cout << "      [3] Savaşcı Yaşı"<< endl;
        cout << "      [4] Çıkış"<< endl;
        cout << "      [*] Lütfen Savaşcıcınız'ın Cinsiyetini Seçiniz!"<< endl;
        cout << "      >>>";
        cin >> data.karaktercinsMenu;
        switch(data.karaktercinsMenu){
        case 1: krcinsiyet = Cinsiyet::Erkek; break;
        case 2: krcinsiyet = Cinsiyet::Kiz; break;
        case 3:  system("cls");
        cout << "      ********************************"<< endl;
        cout << "      ****Savaşcı Yaş Özelleştirme****"<< endl;
        cout << "      ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<< endl;
        cout << "      [*] Lütfen Savaşcıcınız'ın Yaşını Giriniz!"<< endl;
        cout << "      >>>";
        cin >> data.kryas;
        data.karaktercinsMenu=4;
        break;}
        }while(data.karaktercinsMenu !=4);
    }
     void KarakterIsmi(KarakterData &data){
        system("cls");
        string geciciAd;
        bool isimGecerli = false;
        do{
        cout << "      *********************************"<< endl;
        cout << "      ****Savaşcı İsim Özelleştirme****"<< endl;
        cout << "      ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<< endl;
        cout << "      [*] Lütfen Savaşcıcınız'ın İsmini Giriniz!"<< endl;
        cout << "      >>>";
        cin.clear(); // hata durumunu temizle
        cin.ignore(1000, '\n');
        getline(cin,geciciAd);
        if(geciciAd.length() <= 3){cout << "Hata: Isim cok kisa kanka! Adam gibi bir isim ver.\n";Sleep(1000);}
        else if(geciciAd == "aasd" || geciciAd == "admin" || geciciAd == "test"){cout << "Hata: Bu ismi kullanmasan daha iyi kanka, Shadow buna kizar!\n";Sleep(1000);}
        else{data.karakter_adi = geciciAd;isimGecerli = true;}
        }while(isimGecerli == false);
        }
     void KarakterBilgileri(KarakterData &data){
        system("cls");
        cout << "      **************************************"<< endl;
        cout << "      ****Savaşcı Özelleştirme Bilgileri****"<< endl;
        cout << "      ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<< endl;
        cout << "      [*] Savaşcı İsmi: "<< data.karakter_adi <<endl;
        cout << "      [*] Savaşcı Cinsiyeti: "<< CinsiyetToString(krcinsiyet)<<endl;
        cout << "      [*] Savaşcı Boy Ve Kilosu: "<< data.karakterboyu << " cm " << data.karakterkilosu << " kg"<<endl;
        cout << "      [*] Savaşcı Yaşı: "<< data.kryas<<endl;
        cout << "      [*] Savaşcı Saç Rengi: "<< SacRengiToString(sac) <<endl;
        cout << "      [*] Özelleştirilmiş Karakter Bilgileriniz!"<< endl;
        cin.ignore();
        cout << "      [*] Devam Etmek İçin Herhangi Bir Tuşa Basınız!"<< endl;
        cin.get();
        }
     void HatalikayitliKarakter(KarakterData &data){
        system("cls");
        hatatespit = true;
        if(hatatespit == true){
        cout<<"*******************************************************"<<endl;
        if(data.karakter_adi=="Bilinmiyor"){cout<<"       Savaşcının Adı Eksik Savaşcı Oluşturalamadı!\n";} 
        else if(data.kryas <= 18){cout<<"       Savaşcının Cinsiyet Yok Veya Yaşı 18'den Küçük Savaşcı Oluşturalamadı!\n";}
        else if(data.karakterboyu==0 || data.karakterkilosu==0){cout<<"       Savaşcının  Kilo Veya Boyu Eksik Savaşcı Oluşturalamadı!\n";}
        else if(sac == SacRengi::Bos ){cout<<"       Savaşcının Saç Rengi Seçilmemiş Savaşcı Oluşturalamadı!\n";}
        else {hatatespit = false; cout << "Yükleniyor...\n";}
        cout<<"*******************************************************"<<endl;
        Sleep(1000);
        
        }
        }
     void KayitliKarakter(KarakterData &data){
        system("cls");
        cout << "      ______________________________________ "<< endl;
        cout << "     |**************************************|"<< endl;
        cout << "     |***********Savaşcı Bilgileri**********|"<< endl;
        cout << "     |¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|"<< endl;
        cout << "     |[*] Savaşcı İsmi: "<< data.karakter_adi<<endl; 
        cout << "     |[*] Savaşcı Cinsiyeti: "<< CinsiyetToString(krcinsiyet)<<endl;
        cout << "     |[*] Savaşcı Yaşı: "<< data.kryas<< "   |"<< endl;
        cout << "     |[*] Savaşcı Saç Rengi: "<< SacRengiToString(sac)<<endl;
        cout << "     |[*] Savaşcınızı  Başarıyla Oluşturuldu!"<< "|"<< endl; 
        cout << "     ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<< endl; cout << "\n";
        cin.ignore();
        cout << "     |[*] Devam Etmek İçin Herhangi Bir Tuşa Basınız!"<< endl;
        cin.get();
        system("cls");
     }
     void KarakteriKaydet(KarakterData &data){
        ofstream dosyaYaz("karakterOzellikleri.txt");
        if(dosyaYaz.is_open()){
        dosyaYaz << data.karakter_adi << endl;
        dosyaYaz << (int)sac << endl; // Enum'ı sayı olarak kaydederiz
        dosyaYaz << data.karakterboyu << endl;
        dosyaYaz << data.karakterkilosu << endl;
        dosyaYaz << (int)krcinsiyet << endl;
        dosyaYaz << data.kryas << endl;
        dosyaYaz.close();
        cout << "\n     [*] Karakter Başarıyla Kaydedildi!";
        Sleep(1000);
    }
}
     void KarakteriYukle(KarakterData &data) {
    ifstream dosyaOku("karakterOzellikleri.txt");
    if (dosyaOku.is_open()) {
        int tempSac, tempCins;
        getline(dosyaOku, data.karakter_adi);
        dosyaOku >> tempSac; sac = (SacRengi)tempSac; // Sayıyı tekrar Enum'a çevirir
        dosyaOku >> data.karakterboyu;
        dosyaOku >> data.karakterkilosu;
        dosyaOku >> tempCins; krcinsiyet = (Cinsiyet)tempCins;
        dosyaOku >> data.kryas;
        dosyaOku.close();
        cout << "\n[*] Karakter Bilgileri Yüklendi!";
        Sleep(1000);
        KarakterBilgileri(data); // Yüklendikten sonra ekranda göster
        }
        else {
        cout << "\n[!] Kayitli dosya bulunamadi!";
        Sleep(1000);
        }
    
}
     void KaraterOzellestir(KarakterData &data){
        do{
        system("cls");
        cout << "      ****************************"<< endl;
        cout << "      ****Savaşcı Özelleştirme****"<< endl;
        cout << "      ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<< endl;
        cout << "      [1] Karakter Saç Rengi"<< endl;
        cout << "      [2] Karakter Boyu Ve Kilosu"<< endl;
        cout << "      [3] Karakter Cinsiyeti Ve Yaşı"<< endl;
        cout << "      [4] Karakter İsmi"<< endl;
        cout << "      [5] Karakter Bilgileri"<< endl;
        cout << "      [6] Karakteri Kaydet Ve Çık"<< endl;
        cout << "      [7] Ana Menüye Dön"<< endl;
        cout << "      >>>";
        cin >> secim;
        
        switch(secim){
        case 1: KarakterSac(data); break;
        case 2: KarakterBoyKilo(data); break;
        case 3: KarakterCinVyaş(data);break;
        case 4: KarakterIsmi(data); break;
        case 5: KarakterBilgileri(data); break;
        case 6: HatalikayitliKarakter(data);
        if(hatatespit==false){KayitliKarakter(data); KarakteriKaydet(data);}break;
        case 7: break;
        case 20094:data.karakter_adi="Shadow"; sac = SacRengi::Beyaz; data.karakterkilosu=80; data.karakterboyu=180; data.kryas=20; krcinsiyet = Cinsiyet::Erkek; data.karaktercinsMenu=1; break;
        default: cout << "Hatalı Giriş! Ekranda Belirlenen Menülereden Birini Seçiniz!"; Sleep(1500); break;
        }
    }while(secim != 7);
    }
};
class Canavarlar{
    int rastgele;
    int minHasar = 0;
    int maxHasar = 0;
    int minCan = 0;
    int maxCan = 0;
    public:
    void Canavar(CanavarData &hedefcanavar){
    rastgele = 1 + (rand() % 5);
    if(rastgele == 1){
    // 2. Can aralığını belirle: Mesela 80 ile 130 arası olsun
    minCan = 30;
    maxCan = 150;
    minHasar = 10;
    maxHasar = 25;
    // FORMÜL: min + rand() % (max - min + 1)
     hedefcanavar.canavaricani = minCan + (rand() % (maxCan - minCan + 1));
     hedefcanavar.canavarhasar = minHasar + (rand() % (maxHasar - minHasar + 1));
     hedefcanavar.CanavarAdi = "RAGNOR";
     }
    else if(rastgele == 2){
        minCan = 80;
        maxCan = 250;
        minHasar = 20;
        maxHasar = 40;
        hedefcanavar.canavarhasar = minHasar + (rand() % (maxHasar - minHasar + 1));
        hedefcanavar.canavaricani = minCan + (rand() % (maxCan - minCan + 1));
        hedefcanavar.CanavarAdi = "PRAGTA";
    }
    else if(rastgele == 3){
        minCan = 20;
        maxCan = 100;
        minHasar = 5;
        maxHasar = 15;
        hedefcanavar.canavarhasar = minHasar + (rand() % (maxHasar - minHasar + 1));
        hedefcanavar.canavaricani = minCan + (rand() % (maxCan - minCan + 1));
        hedefcanavar.CanavarAdi = "MORTO";
    }
    else if(rastgele == 4){
        minCan = 10;
        maxCan = 80;
        minHasar = 5;
        maxHasar = 10;
        hedefcanavar.canavarhasar = minHasar + (rand() % (maxHasar - minHasar + 1));
        hedefcanavar.canavaricani = minCan + (rand() % (maxCan - minCan + 1));
        hedefcanavar.CanavarAdi = "GOBLİN";
    }
    }
};
class Itemler{
   
    public:
    void Kiliclar(){
        
    }
    void KusanilmisKilic(KarakterItemData &itemdata){ 
        Silah tahtaKilic = {"Tahta Kılıç", 10};
        Silah tasKilic = {"Taş Kılıç", 20};
        Silah elmasKilic = {"Elmas Kılıç", 40};
        Silah Yumruk = {"Yumruk", 2};   
        switch(itemdata.KilicSecme){
        case 1: itemdata.aktifSilah = tahtaKilic; break;
        case 2: itemdata.aktifSilah = tasKilic; break;
        case 3: itemdata.aktifSilah = elmasKilic; break;
        default: itemdata.aktifSilah = Yumruk; break;
        }
    }  
};
class KarakterCanVSaldiri{
    int hasar;
    public:
    void CombotHasari(KarakterItemData &itemdata){
        int combat=0;
        itemdata.combatsans=0;
        int minCb = (itemdata.aktifSilah.hasar * 5) / 100;   
        int maxCb = (itemdata.aktifSilah.hasar * 20) / 100;  
    // ÖNEMLİ: Eğer maxCb ile minCb aynıysa (mesela ikisi de 0 veya 1), 
    // rand() fonksiyonu hata verebilir veya hep aynı sonucu üretir.
    if (maxCb > minCb) {
        combat = minCb + (rand() % (maxCb - minCb + 1));
        itemdata.combatsans += combat;
    } 
    else {
        // Hasar çok düşükse en azından 1-2 bonus verelim ki oyuncu sevinsin
        combat = 1 + (rand() % 5); 
        itemdata.combatsans += combat;
    }
    }
    void CanavarHasari(CanavarData &hedefcanavar, KarakterData &oyuncu){
    oyuncu.can -= hedefcanavar.canavarhasar;
    }
    void Saldiri(CanavarData &hedefcanavar, KarakterItemData &itemdata, KarakterData &oyuncu){

        
        int toplamhasar = itemdata.aktifSilah.hasar + itemdata.combatsans;
        if(itemdata.gucBuff.aktif){
            toplamhasar *= itemdata.gucBuff.hasarCarpan;
            }
            hedefcanavar.canavaricani -= toplamhasar;
        if(itemdata.gucBuff.aktif){
        itemdata.gucBuff.kalanVurus--;
        if(itemdata.gucBuff.kalanVurus <= 0){
        itemdata.gucBuff.aktif = false;
        cout << "\n[!] Güç iksirinin etkisi bitti!";
        }
        }       
        
        cout << "\n ------------------------------------------";
        cout << "\n  >> " << oyuncu.karakter_adi << " saldirdi!";
        cout << "\n  >> Temel Hasar: " << itemdata.aktifSilah.hasar;
        cout << "\n  >> Kombo Bonusu: +" << itemdata.combatsans;
        cout << "\n  >> TOPLAM DARBE: -" << toplamhasar << " HP!";
        cout << "\n ------------------------------------------\n";
        Sleep(300);
        CanavarHasari(hedefcanavar,oyuncu);
        cout <<"<< "<< hedefcanavar.CanavarAdi << "\n'    KÜKREYEREK SALDIRDI: -" << hedefcanavar.canavarhasar << " HP!";
        Sleep(800);
        if(hedefcanavar.canavaricani <= 0)
        {hedefcanavar.canavaricani = 0; system("cls"); 
            int kazanilanxp=50;
             oyuncu.xp+=kazanilanxp;
             oyuncu.toplamxp += kazanilanxp;
            cout << "\n ------------------------------------------\n"; 
            cout <<  hedefcanavar.CanavarAdi <<"            Öldü! Zafer "<< oyuncu.karakter_adi <<"' un!\n";
            cout << "\n       +"<< kazanilanxp <<" XP\n";
            cout << " ------------------------------------------\n"; Sleep(2000); 

             
            if(oyuncu.xp>=100){system("cls"); 
            oyuncu.level++; oyuncu.can = 100; oyuncu.xp -=100;
            cout << "\n ----------------------------------------------------"; 
            cout << "\n      LEVEL ATLADINIZ, SAVAŞCI LEVENİNİZ: "<< oyuncu.level <<" LVL!\n";
            cout << " ------------------------------------------------------\n"; Sleep(2000); 
            }
        }
        if (oyuncu.can <= 0) {
        system("cls");
        oyuncu.can = 0;
        cout << "              --------------------------------------------------------";
        cout << "\n             [!!!] ÖLDÜN... Shadow seninle hayal kırıklığı duyuyor."<< endl;
        Sleep(100);
        cout << "\n             [!!!] OYUN BİTTİ!...\n";
        cout << "              --------------------------------------------------------";
        Sleep(1500);
        }
    }
};
class Envanter{
    int secim;
    int silahsecme;
    public:
    void KilicSec(KarakterData &data, KarakterItemData &itemdata){ system("cls");
        cout << "        -----Kılıçlar-----"<< endl;       
        cout << "      [1] Tahta Kılıç"<< endl;
        cout << "      [2] Taş Kılıç"<< endl;
        cout << "      [3] Elmas Kılıç"<< endl;
        cout << "      [4] Geri Dön"<< endl;
        cout << "      >>>";
        cin >> itemdata.KilicSecme;
        switch (itemdata.KilicSecme)
        {
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: break;
        default:break;
        }
    }
    void SilahSec(KarakterData &data, KarakterItemData &itemdata){ system("cls");
        
        cout << "        -----Silahlar-----  "<< endl;       
        cout << "      [1] Kılıçlar"<< endl;
        cout << "      [2] Yaylar"<< endl;
        cout << "      [3] **"<< endl;
        cout << "      [4] Geri Dön"<< endl;
        cout << "      >>>";
        cin >> silahsecme;
        switch (silahsecme)
        {
        case 1: KilicSec(data,itemdata); break;
        
        default:break;
        }
    }
    void CanLevelBilgi(KarakterData &data){ system("cls");
        cout << "      |"<<data.karakter_adi << " LVL: " << data.level << " |" << endl;
        cout << "      | XP: " << data.xp << " / 100 |" << endl;
        cout << "      |    HP: " << data.can << "    |" << endl;   
        cout << "      | Devam Etmek İçin Herhangi Bir Tuşa Basınız..."<< endl; 
        cin.ignore();
        cin.get();
    }
    void EnvanterAyari(KarakterData &data, KarakterItemData &itemdata){system("cls");
        cout << "      Hangi Yolu Tercih Edeceksin?!"<< endl;       
        cout << "      [1] Envanteri Görüntüle"<< endl;
        cout << "      [2] Silah Seç!"<< endl;
        cout << "      [3] Can & Level Bilgisi"<< endl;
        cout << "      [4] Geri Dön"<< endl;
        cout << "      >>>";
        cin >> secim;

        switch(secim){
            case 1: break;
            case 2: SilahSec(data,itemdata); break;
            case 3: CanLevelBilgi(data); break;
            case 4: break;
        }
    }
    
};
class IksirKullanma{
    public:
    void Can_iksiri(KarakterData &oyuncu, KarakterItemData &itemdata){
        
        if(itemdata.caniskir >=1){
            itemdata.caniskir -=1;
            oyuncu.can +=50;
            if(oyuncu.can >= 100){oyuncu.can =100;}
            cout << "   \nİksir Kullanildi Güncel HP: " << oyuncu.can << endl; 
            Sleep(500);
            system("cls");
            }
            else{
                cout << "   \nMaalesef! İksirin Tükenmiş :C";
                Sleep(500);
                system("cls");
            }
        
    }
    void ikikatiguc(KarakterData &oyuncu, KarakterItemData &itemdata){
        if(!itemdata.gucBuff.aktif && itemdata.saldirIkiKati>0){
           itemdata.gucBuff.aktif = true;
           itemdata.gucBuff.kalanVurus =3;
           itemdata.gucBuff.hasarCarpan = 2.0f;
           itemdata.saldirIkiKati--;
           cout << "     \n[!] GUC IKSRI ICILDI! Hasar 2 katina cikti! (3 Vurus): " << itemdata.saldirIkiKati; 
            Sleep(500);
            system("cls");
           }
           else if(itemdata.saldirIkiKati <= 0){
            cout << "   \nMaalesef! İksirin Tükenmiş :C";
            Sleep(500);
            system("cls");
           }
        
    }
};

class SaldirSaldirma{
    private:
    int sec,vur,iksirsec;
    KarakterCanVSaldiri saldiri;
    CanavarData SuankiCanavar;
    Itemler itemler;
    Canavarlar canavar;
    IksirKullanma iksirkullan;
    public:
    void SaldiriMenu(KarakterData &oyuncu, KarakterItemData &itemdata){
        itemler.KusanilmisKilic(itemdata);
        canavar.Canavar(SuankiCanavar);
        cout << "      ********************************************************************\n";
        cout << "       Savaşmayı Seçtin SHADOW'un İzinden Gidiyorsun Korkusuz Maceracı! =)\n";
        Sleep(1000);
        do{
        system("cls");
        cout << "            O O  O  ✟  O  O O        \n";
        cout << "          __⋀_⋀__⋀__⋀_⋀__⋀_⋀__ \n";
        cout << "      ___|**********************|___\n";
        cout << "     |*****0********O O*******0*****|\n";
        cout << "      |**** THE KNIGHT OF DARK ****|\n";
        cout << "      ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        cout << "      Bu Bir RAGNOR!(Çok Güçlü Değil Gibi?!)"<< endl;
        cout << "      | " << SuankiCanavar.CanavarAdi <<" HP: "<< SuankiCanavar.canavaricani <<" | "<<endl;
        cout << "      | "<< oyuncu.karakter_adi << " "<< oyuncu.can <<" HP Mevcut Canınız! | "<<endl;  
        cout << "      | "<< "[ MEVCUT LEVEL:  "<< oyuncu.level << " LVL! ] | "<<endl;
        cout << "      | "<< " [ "<< oyuncu.xp << "/ 100 ] | \n"<< endl;
        cout << "      [1] Kılıçla Darbe Vur!"<< endl;
        cout << "      [2] İksir Kullan(+)"<< endl;
        cout << "      [3] Geri Çekil!(T-T)"<< endl;
        cout << "      >>>";
        cin >> vur;
        switch(vur){
            case 1: saldiri.CombotHasari(itemdata); saldiri.Saldiri(SuankiCanavar, itemdata,oyuncu); break;
            case 2: iksirmenu(oyuncu,itemdata); break;
            case 3: break;      
        }
        }while(vur !=3 && SuankiCanavar.canavaricani!=0 && oyuncu.can !=0);
        return;
    }
    void SaldiriKarar(KarakterData &oyuncu, KarakterItemData &itemdata){
        do{
        system("cls");
        cout << "            O O  O  ✟  O  O O        \n";
        cout << "          __⋀_⋀__⋀__⋀_⋀__⋀_⋀__ \n";
        cout << "      ___|**********************|___\n";
        cout << "     |*****0********O O*******0*****|\n";
        cout << "      |**** THE KNIGHT OF DARK ****|\n";
        cout << "      ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        cout << "      Görünüşe Göre Karşıda DÜŞMAN Var Onunla Savaşacak Mısın?\n";
        cout << "      [1] Evet!(Korkusuzca)"<< endl;
        cout << "      [2] Yola Gizlice Devam Et!(Ninja)"<< endl;
        cout << "      [3] Köye Kaç!(T-T)"<< endl;
        cout << "      >>>";
        cin >> sec;
        switch(sec){
            case 1: SaldiriMenu(oyuncu,itemdata); break;
            case 2: break;
            case 3: break;
        }
        }while(sec!=3 && oyuncu.can!=0);
        return;
        }
        void iksirmenu(KarakterData &oyuncu, KarakterItemData &itemdata){
            do{
        system("cls");
        cout << "            O O  O  ✟  O  O O        \n";
        cout << "          __⋀_⋀__⋀__⋀_⋀__⋀_⋀__ \n";
        cout << "      ___|**********************|___\n";
        cout << "     |*****0********O O*******0*****|\n";
        cout << "      |**** THE KNIGHT OF DARK ****|\n";
        cout << "      ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        cout << "      İKSİR MENÜSÜNE HOŞGELDİN, KULLANACAĞIN İKSİRİ SEÇ!"<< endl;
        cout << "      | "<< oyuncu.karakter_adi << " "<< oyuncu.can <<" HP Mevcut Canınız! | "<<endl;        
        cout << "      [1] Can İksiri"<< endl;
        cout << "      [2] Güç İkisiri"<< endl;
        cout << "      [3] Geri Çekil!(T-T)"<< endl;
        cout << "      >>>";
        cin >> iksirsec;
        switch(iksirsec){
            case 1: iksirkullan.Can_iksiri(oyuncu,itemdata); break;
            case 2: iksirkullan.ikikatiguc(oyuncu, itemdata); break;
            case 3: break;      
        }
        }while(iksirsec !=3 && SuankiCanavar.canavaricani!=0 && oyuncu.can !=0);
        }
};
class MAP{
    int mapsec;
    SaldirSaldirma saldiriKarar;
    Envanter envanter;
    public:
    void BaslangicYol(KarakterOzellestirme &karakter, KarakterItemData &itemdata, KarakterData &data){ system("cls");
        cout << "      Hangi Yolu Tercih Edeceksin?!"<< endl;       
        cout << "      [1] Ormanlık(!!)"<< endl;
        cout << "      [2] Kasaba!"<< endl;
        cout << "      [3] Envanter"<< endl;
        cout << "      [4] Geri Çekil!(T-T)"<< endl;
        cout << "      >>>";
        cin >> mapsec;
        switch (mapsec)
        {
        case 1: Orman(karakter, itemdata, data); break;
        case 2: Kasaba(); break;
        case 3: envanter.EnvanterAyari(data,itemdata); break;
        case 4: break;
        default:break;
        }
    }
    void Orman(KarakterOzellestirme &asikarakter, KarakterItemData &itemdata, KarakterData &data){system("cls"); int ormanyolu;
        cout << "      Hangi Orman Yolunu Tercih Edeceksin?!"<< endl;       
        cout << "      [1] Dağlara Giden Tümsek"<< endl;
        cout << "      [2] SAĞ Patikatan Git(!)"<< endl;
        cout << "      [3] SOL Patikatan Git(!)"<< endl;
        cout << "      [4] Kraliyet Kalesine Git!"<< endl;
        cout << "      [5] Kasabaya Dön!"<< endl;
        cout << "      [6] Geri Çekil!(T-T)"<< endl;
        cout << "      >>>";
        cin >> ormanyolu;
        switch (ormanyolu)
        {
        case 1: break;
        case 2: saldiriKarar.SaldiriKarar(data, itemdata); break;
        case 3: saldiriKarar.SaldiriKarar(data, itemdata); break;
        case 4: break;
        case 5: Kasaba(); break;
        case 6: break;
        default:break;
        }
    }
    void Kasaba(){ system("cls"); int kasabayolu; 
        cout << "      Kasbada Nereye Gitmek İstiyorsun?"<< endl;       
        cout << "      [1] Ticaretçi"<< endl;
        cout << "      [2] Kraliyet Sarayına"<< endl;
        cout << "      [3] Köylüler İle Sohbet"<< endl;
        cout << "      [4] SHADOW'un Dostu Carlo'nun Yanına(+)"<< endl;
        cout << "      [5] Ormana Git!!"<< endl;
        cout << "      [6] Geri Çekil!(T-T)"<< endl;
        cout << "      >>>";
        cin >> kasabayolu;
        switch (kasabayolu)
        {
        case 1: break;
        
        default:break;
        }
    }
};
class YüklemeCikisEkrani{
        int yükleme=0,cikis=0;
    
    public:
    void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
    
    void YuklemeEkrani(){
        
        system("cls");
        cout << R"(
                 ╔╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╤╗
                 ╟┼┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┼╢
                 ╟┤ _____ _   _ _____   _  ___   _ ___ ____ _   _ _____    ___  _____   ____    _    ____  _  __├╢
                 ╟┤|_   _| | | | ____| | |/ / \ | |_ _/ ___| | | |_   _|  / _ \|  ___| |  _ \  / \  |  _ \| |/ /├╢
                 ╟┤  | | | |_| |  _|   | ' /|  \| || | |  _| |_| | | |   | | | | |_    | | | |/ _ \ | |_) | ' / ├╢
                 ╟┤  | | |  _  | |___  | . \| |\  || | |_| |  _  | | |   | |_| |  _|   | |_| / ___ \|  _ <| . \ ├╢
                 ╟┤  |_| |_| |_|_____| |_|\_\_| \_|___\____|_| |_| |_|    \___/|_|     |____/_/   \_\_| \_\_|\_\├╢
                 ╟┼┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┼╢
                 ╚╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╝)"<< endl;
        cout << "                                                          OYUN YÜKLENİYOR...    \n";
        for(int i=0; i <= 100; i+=5){
        gotoxy(8, 11);
        cout << "               | ";
        for(int j = 0; j <= yükleme; j++){cout <<"█" << " ";}
        cout << "|\n"<<"                                                               [ %" <<i<< " ]";
        if(i <= 80){yükleme++; Sleep(75); yükleme++; Sleep(75);}
        else{yükleme++;  Sleep(125); yükleme++; Sleep(125);}
        }
    Sleep(500);
    system("cls"); 
    }
    void CikisEkrani(){    
        system("cls");
        cout << "      ____  _               _               " << endl;
        cout << "     / ___|| |__   __ _  __| | _____      __" << endl;
        cout << "     \\___ \\| '_ \\ / _` |/ _` |/ _ \\ \\ /\\ / /" << endl;
        cout << "      ___) | | | | (_| | (_| | (_) \\ V  V / " << endl;
        cout << "     |____/|_| |_|\\__,_|\\__,_|\\___/ \\_/\\_/  " << endl;
        cout << "               THE KNIGHT OF DARK             " << endl;  
        cout << "\n";
        
        
        for(int i=0; i <= 100; i+=5){
        gotoxy(0, 9);
        cout << "             OYUN KAYDEDİLİYOR!\n"; 
        cout << "                  ELVEDA!\n";
        for(int j = 0; j <= cikis; j++){cout <<"*" << " ";}
        if(i <= 80){cikis++;Sleep(90);}
        else if(i > 80){cikis++;Sleep(160);}
        }
        cout << "           \nOYUN KAYDELDİ KAPANIYOR!";
    Sleep(500);
    system("cls"); 
}
};
 class KaydetVeri{
        public:
        void OyuncuVeriKaydet(KarakterItemData &itemdata, KarakterData &data, KarakterOzellestirme &karakter){
        ofstream dosyaYaz("KarakterVerileri.txt");
        if(dosyaYaz.is_open()){
        dosyaYaz << data.can << endl;
        dosyaYaz << data.level << endl;
        dosyaYaz << data.toplamxp << endl;
        dosyaYaz << data.xp << endl;
        dosyaYaz << data.xpbilgi << endl;
        dosyaYaz << itemdata.caniskir << endl;
        dosyaYaz << itemdata.aktifSilah.hasar << endl;
        dosyaYaz << itemdata.saldirIkiKati << endl;
        dosyaYaz << itemdata.aktifSilah.isim << endl;
        dosyaYaz << itemdata.KilicSecme << endl;
        dosyaYaz.close();
        cout << "\n     [*] Oyun Başarıyla Kaydedildi!";
        Sleep(1000);
        karakter.KayitliKarakter(data);
    }
}

void OyuncuVeriYukle(KarakterItemData &itemdata, KarakterData &data, KarakterOzellestirme &karakter) {
    ifstream dosyaOku("KarakterVerileri.txt");
    if (dosyaOku.is_open()) {
        dosyaOku >> data.can;
        dosyaOku >> data.level;
        dosyaOku >> data.toplamxp;
        dosyaOku >> data.xp;
        dosyaOku >> data.xpbilgi;
        dosyaOku >> itemdata.caniskir;
        dosyaOku >> itemdata.aktifSilah.hasar;
        dosyaOku >> itemdata.saldirIkiKati;
        dosyaOku >> itemdata.aktifSilah.isim;
        dosyaOku >> itemdata.KilicSecme;
        dosyaOku.close();
        cout << "\n[*] Oyun Bilgileri Yüklendi!";
        Sleep(1000);
        }
        else {
        cout << "\n[!] Oyun dosya bulunamadi!";
        Sleep(1000);
        }
        karakter.KarakteriYukle(data);
}
    };
class OyunBasla{
        int sec;
        MAP map;
        KaydetVeri kaydet;
        public:
        void OyunBaslaAnaMenu(KarakterOzellestirme &karakter, KarakterItemData &itemdata, KarakterData &data){ 
        do{
        system("cls");
        cout << "            O O  O  ✟  O  O O        \n";
        cout << "          __⋀_⋀__⋀__⋀_⋀__⋀_⋀__ \n";
        cout << "      ___|**********************|___\n";
        cout << "     |*****0********O O*******0*****|\n";
        cout << "      |**** THE KNIGHT OF DARK ****|\n";
        cout << "      ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        cout << "      ******************************"<< endl;
        cout << "      ***   O     Y    U      N   ***"<< endl;
        cout << "      ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<< endl;
        cout << "      [1] Kayıtlı Oyundan Devam Et!"<< endl;
        cout << "      [2] Yeni Oyuna Başla!"<< endl;
        cout << "      [3] Ana Menüye Dön"<< endl;
        cout << "      >>>";
        cin >> sec;
        switch(sec){
            case 1: kaydet.OyuncuVeriYukle(itemdata, data, karakter); map.BaslangicYol(karakter,itemdata, data); break;
            case 2: map.BaslangicYol(karakter, itemdata, data); break;
            case 3: continue; break;
        }
        }while(sec!=3);
        }
};

class AnaMenu{
    int sec_menu;
    YüklemeCikisEkrani Ekran;
    OyunBasla OyunAnaMenu;
    KaydetVeri kaydet;
    public:
    void menu(KarakterItemData &itemdata, KarakterData &data, KarakterOzellestirme &karakter){
        bool devamEt =true;
        do{ system("cls");
        cout << "            O O  O  ✟  O  O O        \n";
        cout << "          __⋀_⋀__⋀__⋀_⋀__⋀_⋀__ \n";
        cout << "      ___|**********************|___\n";
        cout << "     |*****0********O O*******0*****|\n";
        cout << "      |**** THE KNIGHT OF DARK ****|\n";
        cout << "      ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
        cout << "      ******************************"<< endl;
        cout << "      ***  𝓗 𝓞 Ş 𝓖 𝓔 𝓛 𝓓 İ 𝓝 İ 𝓩 ***"<< endl;
        cout << "      ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<< endl;
        cout << "      [1] Oyuna Başla!"<< endl;
        cout << "      [2] Karakter Özelleştirme"<< endl;
        cout << "      [3] Ayarlar"<< endl;
        cout << "      [4] Credit"<< endl;
        cout << "      [5] Kaydet Ve Oyundan Çık!"<< endl;
        cout << "      [6] Kaydetmeden Oyundan Çık!"<< endl;
        cout << "      >>>";
        cin >> sec_menu;
        switch(sec_menu){
        case 1: system("cls"); /* krkozel.HatalikayitliKarakter(); if(krkozel.hatatespit == false) */ OyunAnaMenu.OyunBaslaAnaMenu(karakter, itemdata, data); break;
        case 2: karakter.KaraterOzellestir(data); break;
        case 3: break;
        case 4: break;
        case 5: kaydet.OyuncuVeriKaydet(itemdata, data, karakter); Ekran.CikisEkrani(); devamEt=false;break;
        case 6: system("cls"); cout << "\n          Oyun Kapanıyor, Elveda! Savaşcı!"; Sleep(3000); devamEt=false; break;
        }
        }while(devamEt);
        }
    };
int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    srand(time(0));
    YüklemeCikisEkrani Ekran;
    KarakterItemData itemdata;
    KarakterData data;
    KarakterOzellestirme karakter;
    Ekran.YuklemeEkrani();
    AnaMenu Amenu;
    Amenu.menu(itemdata, data, karakter);
    return 0;
}