#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <stdexcept>

/*
===============================================================================
                            ITERATOR CHEATSHEET
===============================================================================

Iterator nedir?
---------------
Iterator, container icindeki elemanlari gezmek icin kullanilan bir "isaretci gibi"
yapidir.

Pointer'a benzer:
    int arr[3] = {10, 20, 30};
    int *p = arr;
    std::cout << *p;      // 10
    ++p;
    std::cout << *p;      // 20

Iterator da ayni fikirdir:
    std::vector<int>::iterator it = v.begin();
    std::cout << *it;
    ++it;

Ama iterator sadece array icin degil, vector/list/map/set gibi STL containerlar
icin genel bir gezinme aracidir.

-------------------------------------------------------------------------------
BILMEN GEREKEN TEMEL KAVRAMLAR
-------------------------------------------------------------------------------

1) begin()
   Container'in ilk elemanini gosteren iterator dondurur.

2) end()
   Son elemandan bir sonraki hayali yeri gosterir.
   Dikkat: end() bir eleman degildir. Dereference edilmez.

3) *it
   Iteratorun gosterdigi elemani verir.

4) ++it
   Bir sonraki elemana gecer.

5) it == container.end()
   Iterator sona geldi mi diye kontrol edilir.

-------------------------------------------------------------------------------
ITERATOR TURleri
-------------------------------------------------------------------------------

1) iterator
   Normal iterator. Elemani okuyabilir ve degistirebilir.

2) const_iterator
   Elemani okuyabilir ama degistiremez.
   const container gezerken kullanilir.

3) reverse_iterator
   Container'i sondan basa dogru gezer.

4) const_reverse_iterator
   Sondan basa okur ama degistiremez.

-------------------------------------------------------------------------------
CONTAINER'A GORE ITERATOR GUCU
-------------------------------------------------------------------------------

vector / deque:
    ++it, --it, it + n, it - n, it[0] gibi islemler desteklenir.
    Bunlar random access iterator kullanir.

list:
    ++it ve --it desteklenir.
    Ama it + n YOKTUR.
    Cunku list bellekte yan yana durmaz.

set / map:
    ++it ve --it desteklenir.
    Elemanlar sirali tutulur.
    set icinde eleman degeri degistirilemez.
    map icinde key degistirilemez, value degistirilebilir.

-------------------------------------------------------------------------------
EN ONEMLI KURAL
-------------------------------------------------------------------------------

end() dereference edilmez:

    std::cout << *v.end(); // YANLIS

Cunku end() son elemani degil, sonrasini gosterir.

===============================================================================
*/

static void printTitle(const std::string& title)
{
    std::cout << "\n==================== " << title << " ====================\n";
}

/*
Generic print fonksiyonu.
T herhangi bir container olabilir.
Container'in iterator type'i T::const_iterator olarak alinir.

Neden typename var?
-------------------
Template icinde T::const_iterator yazinca compiler bunun bir type oldugunu
bilemez. Bu yuzden C++98'de basina typename koyariz.
*/
template <typename T>
void printContainer(const T& container)
{
    typename T::const_iterator it;

    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

/*
42 Module 08 ex00 easyfind mantigi.
Container icinde int arar.
Bulursa iterator dondurur.
Bulamazsa exception atar.
*/
template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found");
    return it;
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
    typename T::const_iterator it;

    it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found");
    return it;
}

void exampleVectorIterator(void)
{
    printTitle("VECTOR ITERATOR");

    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::vector<int>::iterator it;

    std::cout << "Vector elemanlari: ";
    for (it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // iterator ile eleman degistirme
    it = v.begin();
    *it = 999;

    std::cout << "Ilk eleman iterator ile degistirildi: ";
    printContainer(v);

    // vector random access destekler
    it = v.begin();
    std::cout << "v.begin()      = " << *it << std::endl;
    std::cout << "v.begin() + 1  = " << *(it + 1) << std::endl;
    std::cout << "v.begin() + 2  = " << *(it + 2) << std::endl;
}

void exampleConstIterator(void)
{
    printTitle("CONST_ITERATOR");

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    const std::vector<int>& cv = v;
    std::vector<int>::const_iterator it;

    std::cout << "Const vector okuma: ";
    for (it = cv.begin(); it != cv.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // Bu satir compile error verir, cunku const_iterator ile degistirme yapilamaz:
    // *it = 42;
}

void exampleReverseIterator(void)
{
    printTitle("REVERSE_ITERATOR");

    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    std::vector<int>::reverse_iterator rit;

    std::cout << "Tersten yazdirma: ";
    for (rit = v.rbegin(); rit != v.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;

    /*
    rbegin() son elemani gosterir.
    rend() ilk elemandan onceki hayali yeri gosterir.
    */
}

void exampleListIterator(void)
{
    printTitle("LIST ITERATOR");

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(15);

    std::list<int>::iterator it;

    std::cout << "List elemanlari: ";
    for (it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    it = lst.begin();
    ++it;
    std::cout << "Ikinci eleman: " << *it << std::endl;

    // List random access desteklemez:
    // it = it + 1; // Compile error
}

void exampleSetIterator(void)
{
    printTitle("SET ITERATOR");

    std::set<int> s;
    s.insert(30);
    s.insert(10);
    s.insert(20);
    s.insert(20); // duplicate eklenmez

    std::set<int>::iterator it;

    std::cout << "Set elemanlari sirali gelir: ";
    for (it = s.begin(); it != s.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // set icinde eleman degistirilemez.
    // Cunku degistirirsen siralama bozulabilir.
    // *it = 999; // Compile error
}

void exampleMapIterator(void)
{
    printTitle("MAP ITERATOR");

    std::map<std::string, int> ages;
    ages["Vedat"] = 22;
    ages["Ali"] = 30;
    ages["Ayse"] = 25;

    std::map<std::string, int>::iterator it;

    for (it = ages.begin(); it != ages.end(); ++it)
    {
        std::cout << "key: " << it->first
                  << ", value: " << it->second << std::endl;
    }

    // map iterator pair dondurur:
    // it->first  = key
    // it->second = value

    it = ages.find("Vedat");
    if (it != ages.end())
    {
        it->second = 23; // value degisebilir
        // it->first = "Mehmet"; // key degisemez
    }

    std::cout << "Vedat yeni yas: " << ages["Vedat"] << std::endl;
}

void exampleStdFind(void)
{
    printTitle("STD::FIND + ITERATOR");

    std::vector<int> v;
    v.push_back(7);
    v.push_back(14);
    v.push_back(21);

    std::vector<int>::iterator it;

    it = std::find(v.begin(), v.end(), 14);

    if (it != v.end())
        std::cout << "14 bulundu: " << *it << std::endl;
    else
        std::cout << "14 bulunamadi" << std::endl;

    it = std::find(v.begin(), v.end(), 99);

    if (it != v.end())
        std::cout << "99 bulundu: " << *it << std::endl;
    else
        std::cout << "99 bulunamadi, iterator end() oldu" << std::endl;
}

void exampleEasyfind(void)
{
    printTitle("EASYFIND EXAMPLE");

    std::vector<int> v;
    v.push_back(100);
    v.push_back(200);
    v.push_back(300);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 200);
        std::cout << "Bulundu: " << *it << std::endl;

        *it = 999;
        std::cout << "Iterator ile deger degistirildi: ";
        printContainer(v);
    }
    catch (const std::exception& e)
    {
        std::cout << "Hata: " << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(v, 404);
        std::cout << "Bulundu: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Hata: " << e.what() << std::endl;
    }
}

void exampleIteratorInvalidation(void)
{
    printTitle("ITERATOR INVALIDATION");

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::vector<int>::iterator it = v.begin();

    std::cout << "Iterator ilk elemani gosteriyor: " << *it << std::endl;

    /*
    DIKKAT:
    vector'a push_back yapinca kapasite yetmezse vector bellekte yeni bir yer acar.
    Bu durumda eski iteratorlar gecersiz olabilir.

    Yani su risklidir:
        it = v.begin();
        v.push_back(4);
        std::cout << *it; // Bazen calisir, bazen patlar. Undefined behavior.

    Guvenli yol:
        Degisiklikten sonra iteratoru yeniden al.
    */

    v.push_back(4);
    it = v.begin();

    std::cout << "push_back sonrasi iterator yeniden alindi: " << *it << std::endl;
}

int main(void)
{
    exampleVectorIterator();
    exampleConstIterator();
    exampleReverseIterator();
    exampleListIterator();
    exampleSetIterator();
    exampleMapIterator();
    exampleStdFind();
    exampleEasyfind();
    exampleIteratorInvalidation();

    return 0;
}

/*
===============================================================================
KISA OZET
===============================================================================

Iterator = container icinde gezen pointer benzeri nesne.

En cok kullanilan pattern:

    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << std::endl;

begin() = ilk eleman
end()   = son elemandan sonraki hayali yer
*it     = iteratorun gosterdigi eleman
++it    = sonraki elemana gec

Normal iterator:
    std::vector<int>::iterator it;
    *it = 42; // degistirebilir

Const iterator:
    std::vector<int>::const_iterator it;
    *it = 42; // yasak

Reverse iterator:
    rbegin() -> sondan baslar
    rend()   -> bastan onceki hayali yer

vector:
    it + n var

list:
    it + n yok, sadece ++it / --it

map:
    it->first  = key
    it->second = value

set:
    eleman degistirilmez

end() ASLA dereference edilmez:
    *container.end(); // YANLIS

===============================================================================
*/
