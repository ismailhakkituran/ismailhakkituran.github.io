

## IMMUTABLE Veri Tipleri (değer değişmez – primitive gibi davranır)

Java’da şu tipler immutabledır:

int, double, boolean (primitive kopyalanır)
String
Integer, Double (wrapper sınıflar)
LocalDate, LocalDateTime

### Integer

```c
int a = 10;
int b = a;

b = 20;

System.out.println(a); // 10 (değişmez)
System.out.println(b); // 20
```
Primitive tiplerde değer kopyalanır, değişiklik orijinale etki etmez.

### String

```java
String s1 = "Hello";
String s2 = s1;

s2 = "World";

System.out.println(s1); // "Hello"
System.out.println(s2); // "World"
```

## MUTABLE Veri Tipleri (değiştirilebilir – referans davranışı)

Java’da mutable yapı örnekleri:

ArrayList
HashMap
Array (dizi)
StringBuilder
Custom class içindeki field’lar değişebilir

```java
List<Integer> list1 = new ArrayList<>(List.of(1, 2, 3));
List<Integer> list2 = list1;

list2.set(0, 99);

System.out.println(list1); // [99, 2, 3]
System.out.println(list2); // [99, 2, 3]
```
list1 ve list2 aynı nesneyi referans ediyor, biri değişince diğeri de değişir.

## Dizi örneği (array mutabledır)

```java
int[] arr1 = {1, 2, 3};
int[] arr2 = arr1;

arr2[0] = 10;

System.out.println(Arrays.toString(arr1)); // [10, 2, 3]
```

Aşağıdaki örnek hem mutable hem immutable farkını tek yerde gösteriyor:

```java
String text = "hello";
text.toUpperCase();
System.out.println(text);  // "hello"  (immutable – değişmedi)
```

Peki ya şöyle olsaydı?
```java
text.toUpperCase();
```







## MUTABLE List

```java
List<Integer> numbers = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5));

// MUTABLE -> orijinal listeyi değiştirir
for (int i = 0; i < numbers.size(); i++) {
    numbers.set(i, 42);   // elemanların gerçek değerleri değişiyor
}

System.out.println(numbers); 
// Çıktı: [42, 42, 42, 42, 42]
```

## IMMUTABLE List

```java
List<Integer> immutableList = List.of(1, 2, 3, 4, 5);

// IMMUTABLE -> set() metodu yok, değiştirilemez
for (int i = 0; i < immutableList.size(); i++) {
    // immutableList.set(i, 42);   // Derleme hatası: UnsupportedOperationException
}
```
