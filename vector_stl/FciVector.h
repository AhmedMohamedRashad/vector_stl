#ifndef FCIVECTOR_H
#define FCIVECTOR_H
#include <string>

using namespace std;
class courses
{
private:
    string courseName,courseCode;
    char courseGrade;
    float coursePoint;
    int courseYear,courseSemester;

public:
    courses() {}
    void add()
    {
        cout<<"enter course name : "; cin>>courseName;
        cout<<"enter course code : "; cin>>courseCode;
        cout<<"enter course grade : "; cin>>courseGrade;
        cout<<"enter course point : "; cin>>coursePoint;
        cout<<"enter course year : "; cin>>courseYear;
        cout<<"enter course semester : "; cin>>courseSemester;
    }
    void printCourseInfo()
    {
        cout<<" course name : " << courseName<<endl;
        cout<<" course code : " << courseCode<<endl;
        cout<<" course grade : " << courseGrade<<endl;
        cout<<" course point : " << coursePoint<<endl;
        cout<<" course year : " << courseYear<<endl;
        cout<<" course semester : "<< courseSemester<<endl;
    }
    ~courses() {}

};

template <class t>
class FciVector
{
private:
    t* elements,*temp;//two array dynamic
    int numberOfElements=0,capacity=0;
public:
    FciVector()
    {

        elements=new t[0];//initial dynamic array

    }
    int getsize()
    {
        return numberOfElements;
    }
    int getcapacity()
    {
        return capacity;
    }
    bool isempty()
    {
        return (numberOfElements<1);//this return true (1) if size less than 1
    }
    t operator [](int n)
    {
        return elements[n];
    }
    t Back()           //return last element
    {
        return elements[numberOfElements-1];
    }
    t Front()  // return first elemennt
    {
        return elements[0];
    }
    void Insert (int n,t val)
    {

        temp=new t [numberOfElements];
        for(int i=0 ; i<numberOfElements; i++)
            temp[i]=elements[i];
        delete []elements;
        elements=new t[numberOfElements+1];
        int counter=0;
        for(int i=0; i<numberOfElements; i++)
        {
            if(counter==n)
                counter++;
            elements[counter]=temp[i];
            counter++;
        }

        elements[n]=val;
        delete []temp;
        numberOfElements++;
        capacity++;
    }
    t Begin()
    {
        return &elements[0];
    }
    void Erase(int n)
    {

        temp=new t[numberOfElements];
        for(int i=0 ; i<numberOfElements; i++)
            temp[i]=elements[i];
        delete []elements;
        numberOfElements--;
        elements=new t[numberOfElements];
        int counter=0;
        for(int i=0; i<numberOfElements; i++)
        {
            if(counter==n)
                counter++;
            elements[i]=temp[counter];
            counter++;
        }
        delete[] temp;

    }
    void Clear()
    {
        numberOfElements=0;
        delete []elements;
    }

    ~FciVector()
    {
        delete []elements;
    }




};
class students
{
private:
    string sname,sdepartment;
    int sid;



public:
    FciVector <courses> course;
    students() {}

    void store()
    {
        cout<<"enter student name : "; cin>>sname;
        cout<<"enter student Id : "; cin>>sid;
        cout<<"enter student department : "; cin>>sdepartment;

    }
    void printInfo()
    {
        cout<<" student name : "<<sname<<endl;
        cout<<" student Id : "<<sid<<endl;
        cout<<" student department : "<<sdepartment<<endl;

    }
    ~students() {}



};

template<class t>
void operations()
{
    FciVector<t> obj;
    int n; t k;

    here:cout<<"What kind of operation would you like to perform?\n"
        <<"1. Add element.\n2. Remove last element.\n3. Insert element at certain position.\n"
        <<"4. Erase element from a certain position.\n5. Clear.\n6. Display first element.\n"
        <<"7. Display last element.\n8. Display element at certain position.\n"
        <<"9. Display vector size.\n10. Display vector capacity.\n11. Is empty?\n";
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1 :
            {
            cout<<"How many elements you would like to add?\n";
            cin>>n;
            cout<<"Enter elements\n";
            for(int i=0;i<n;i++)
            {
                cin>> k;
                obj.Insert(obj.getsize(),k);
            }
            cout<<"add successfully\n";

            break;}
            case 2 :
            {
                if(obj.getsize()>0)
                obj.Erase(obj.getsize()-1);
                else
                {
                    cout<<"does not exist any elements\n";
                    goto here;
                }
                cout<<"remove successfully\n";

            break;}
            case 3 :
            {
                cout<<"Enter index start from 1\n";
                cin>>n;
                if(n>0 &&n<=obj.getsize())
                {
                    cout<<"enter the element\n";
                    cin>>k;
                    obj.Insert(n-1,k);
                    cout<<"insert successfully.\n";
                }
                else
                {
                    cout<<"not found\n ";
                    goto here;
                }

            break;}
            case 4:
            {
                cout<<"Enter index start from 1\n";
                cin>>n;
                if(n>0 &&n<=obj.getsize())
                {
                  obj.Erase(n-1);
                  cout<<"erase successfully.\n";
                }
                else
                {
                    cout<<"not found\n ";
                    goto here;
                }
            break;}
            case 5 :
            {
                    obj.Clear();
                    cout<<"clear successfully.\n";
            break;}
            case 6:
            {
                if(obj.getsize()>0)
               {

                k=obj.Front();
                cout<<"first element is :"<<k<<endl;

               }
               else
                    {
                    cout<<"does not exist any elements\n";
                    goto here;
                }
            break;}
            case  7 :
            {
                if(obj.getsize()>0)
               {

                k=obj.Back();
                cout<<"last element is :"<<k<<endl;

               }
               else
                    {
                    cout<<"does not exist any elements\n";
                    goto here;
                }

            break;}
            case 8 :
            {
                cout<<"Enter index start from 1\n";
                cin>>n;
                if( n>0 && n<=obj.getsize())
                {
                  cout<<"element of index["<<n<<"] : "<<obj[n-1]<<endl;
                }
                else
                {
                    cout<<"not found\n ";
                    goto here;
                }

            break;}
            case  9 :
            {
                    cout<<"vector size :  "<<obj.getsize()<<endl;
            break;}
            case 10 :
            {
                cout<<"vector capacity :  "<<obj.getcapacity()<<endl;
            break;}
            case  11 :
            {
                cout<<(obj.isempty()==1?"Yes this vector empty\n":"no this vector not empty\n");

            break;}
            default:
            {
                cout<<"invalid choice!!!\n";
            break;}
        }
        h1: cout<<"Would you like to perform other operations? (Y/N)\n";
        char c;
        cin>>c;
        if(c=='Y'||c=='y')
            goto here;
        else if(c!='N' && c!='n')
        {
            cout<<"invalid input\n";
            goto h1;
        }
        else{}


}





#endif // FCIVECTOR_H

