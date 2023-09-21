#if !defined(_ARRAYLIST_H)
#define _ARRAYLIST_H
class Arraylist
{
 private:       //สมาชิกประเภทนี้สามารถเข้าถึงได้โดยคลาสและออบเจ็คเดียวกัน
   int *L;      //ตัวข้อมูล
   int maxSize; //จำนวนข้อมูลมากสุด
   int curSize; //จำนวข้อมูลปัจุบัน
   
   
 public:        //สมาชิกประเภทนี้สามารถเข้าถึงได้ทุกส่วนของโปรแกรม
  Arraylist(int maxSize); //คอนสตรัคเตอร์เป็นฟังก์ชันพิเศษที่จะถูกเรียกใช้เมื่อออบเจ็คถูกสร้าง เป้าหมายของมันเพื่อสำหรับกำหนดค่าเริ่มต้นให้กับออบเจ็ค คอนสตรัคเตอร์ใช้ชื่อเดียวกับคลาส
  ~Arraylist();//dest
  int size(); // ดูค่าปัจจุบัน
  int get(int i);  // หาว่าต่ำเเหน่งที่มีค่าอะไร
  int remove(int i);// ลบข้อมูลในอาเรย์
  int indexof(int e); // หาว่าตัวที่ e อยู่ตรงไหน
  void set(int i ,int e); // ใส่ค่า e ไปยังต่ำเเหน่งที่ i อยู่
  void add(int i , int e);
  void Clear();
  int Max();
  int Min();
  void display();


};


#endif // _MYCODE_H_
