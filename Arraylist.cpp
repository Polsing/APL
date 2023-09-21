#include "Arraylist.h"
#include <iostream>
using namespace std;

 Arraylist::Arraylist(int maxSize) //สถานะเริ่มต้นการสร้างคลาส โดยรับค่า  จาก private
 {
    this->maxSize = maxSize;  // this หมายที่นี่ ณที่นี้
    curSize = 0;
    L = new int [this->maxSize]; //สร้าง อาเรย์ เท่ากับจำนวน maxSize "new คือการสร้างใหม่"
   // cout <<"start working"<<endl;
 }

 Arraylist::~Arraylist() // mamerry มีจำกัด ต้องทำลาย เพราะว่ามีการจอง mamerry 
 {
    delete []L; // ลบข้อมูลในอาเรย์ของ L
   // cout <<"Deleted L[] done^^"<<endl;

 }

 int  Arraylist::size() //ดูค่าปัจจุบัน
 {
    return curSize;
 }

 int  Arraylist::get(int i) //หาว่าต่ำเเหน่งที่มีค่าอะไร
 {
    if(curSize == 0)//เช็คก่อนว่ามีสมาชิกมั้ย
    {
      return -1;                        //ให้รีเทริน เพื่อหยุดการทำงาน
    }
     if(i<0 )//เช็คว่าสมาชิกมีจำนวน 0 ถึง curSize -1 หรือป่าว หรือ 0ถึง0 หรือข้อมุลที่เราอ้างถึงอยู่ในช่วง 0 ถึง curSize(ขนาดปัจจุบัน)หรือป่าว
    {
      return -1;
    }
    else if( i>curSize-1)//เช็คว่าสมาชิกมีจำนวน 0 ถึง curSize -1 หรือป่าว หรือ 0ถึง0 หรือข้อมุลที่เราอ้างถึงอยู่ในช่วง 0 ถึง curSize(ขนาดปัจจุบัน)หรือป่าว
    {
      return -1;
    }
    return L[i];  //ถ้าอยู่ในช่วงที่กำหนดเเล้ว
 }

 int  Arraylist::remove(int i)// ลบข้อมูลในอาเรย์
 {

    if (curSize <= 0)//เช็คว่าสมาชิกมีจำนวน 0 ถึง curSize -1 หรือป่าว หรือ 0ถึง0 หรือข้อมุลที่เราอ้างถึงอยู่ในช่วง 0 ถึง curSize(ขนาดปัจจุบัน)หรือป่าว
    {
        cout << "Error: List is empty" << endl;
        return -1;
    }

    if (i<0)//เช็คว่าสมาชิกมีจำนวน 0 ถึง curSize -1 หรือป่าว หรือ 0ถึง0 หรือข้อมุลที่เราอ้างถึงอยู่ในช่วง 0 ถึง curSize(ขนาดปัจจุบัน)หรือป่าว
    {
        cout <<"Error: is under lower bound"<< endl;
        return -1;
    }
    else if (i> curSize-1)
    {
       cout<<"Error: i is over upper bound"<<endl;
       return -1;
    }

    int temp = L[i];

    for(int j = i+1; j<=curSize-1 ; j++)
        L[j-1] = L[j];

        curSize--;

    return temp;
 }

 int  Arraylist::indexof(int e) // หาว่าตัวที่ e อยู่ตรงไหน
 {
  int i;
    for ( i = 0; i <=curSize-1 ; i++) //วนลูปเพื่อเช็คต่ำเเหน่ง
        if (L[i] == e)
        return i;
        
    cout<<"Data "<< e <<" This information is not available. "<<endl; // ถ้าไม่มีข้อมูลที่ตรงกัน ให้เเสดงข้อความนี้
    return -1;
  }

 void Arraylist::set(int i, int e) // ใส่ค่า e ไปยังต่ำเเหน่งที่ i อยู่
 {
   if (i < 0) //เช็คว่าสมาชิกมีจำนวน 0 ถึง curSize -1 หรือป่าว หรือ 0ถึง0 หรือข้อมุลที่เราอ้างถึงอยู่ในช่วง 0 ถึง curSize(ขนาดปัจจุบัน)หรือป่าว
    {
        cout << "SET: " << i << " is lower bound, This not set" << endl;
    }
   else if(i >= curSize)//เช็คว่าสมาชิกมีจำนวน 0 ถึง curSize -1 หรือป่าว หรือ 0ถึง0 หรือข้อมุลที่เราอ้างถึงอยู่ในช่วง 0 ถึง curSize(ขนาดปัจจุบัน)หรือป่าว
   {
        cout << "SET: " << i << " is upper bound, This not set" << endl;
   }

   else // อยู่ในช่วงที่กำหนด
       // cout << "Setposition: " << i <<" to "<< e <<" done "<< endl;
        L[i] = e;

 }

 void Arraylist::add(int i, int e) // ใส่ค่าในอาเรย์
 {
  if(curSize == maxSize)//เช้คก่อนว่า curSize (ค่าปัจจุบัน)ว่าเต็มไหม
  {
    cout<<"Error:"<<e<<" list is full"<<endl; //ถ้าเต็มให้เเสดงข้อความนี้
    return;
  }
              //ถ้าไม่เต็มให้ทำต่อไปนี้
    if(i<0) //check lower bound (warning)
    {
      cout<<"Waring: i is under lower bound, i change to 0"<<endl;
      i=0;
    }
    else if(i>curSize) //check upper bound (warning)
    {
      cout<<"Waring: i is over upper bound, i change to "<< curSize<<endl;
      i = curSize;
    }
    //ถ้ารอดจากเงื่อนไขข้างต้น เเสดงว่าต่ำเเหน่ง ok เเล้ว
    for(int j = curSize-1; j>=i ; j--)//อันนี้คือเช็คก่อนว่า มีห้องไหนว่างมั่ง เพราะเราไม่สามารถไปใส่ค่าทับต่ำเเหน่งนั้นๆได้
    
      L[j+1] = L[j];
      L[i] = e;
      curSize++;
 }

 void Arraylist::Clear()
 {
   cout<<"Delete Data L[] done."<<endl;
   curSize = 0;
  
 }

 int  Arraylist::Max()
 {
   int max = L[0];
   for(int i=0; i<=curSize-1; i++ ) 
    {
     if(max < L[i])
     {
      max = L[i];
     }
    }
  return max;
 }

 int  Arraylist::Min()
 {
    int min = L[0];
    for (int i=0; i <=curSize-1; i++)
     {
      if(min > L[i])
      {
        min = L[i];
      }
     }
   return min;
 }

 void Arraylist::display()
 {
    cout<<"L:[ ";
    if(curSize == 0)
    cout<<"]";
    else
    {
       for(int i=0; i<curSize;i++)
       {
       cout<<L[i];
       if(i<curSize-1)
       cout<<" : ";
       else
       cout<<"]";
       }
    }
    cout<<" size:"<<curSize<<"/"<<maxSize<<endl;
 }
