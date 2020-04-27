#include <iostream>
#include <FciVector.h>
#include <string>
using namespace std;

int main()
{
hh: cout<<"Insert type of vector you would like to create:\n1. list of integer\n2. list of character\n3. list of string"
<<"\n4. list of float\n5. list of students\n6. Exit\n";
char choice;cin>>choice;
switch(choice)
{
        case '1':
            {
            cout<<"A vector of char was created successfully.\n";
                    operations<int>();
                    goto hh;
            break;
            }
        case '2':
            {

            cout<<"A vector of char was created successfully.\n";
                operations<char>();
                    goto hh;

            break;
            }
        case '3':
            {

                cout<<"A vector of string was created successfully.\n";
                operations<string>();
                    goto hh;

            break;
            }
        case '4':
            {
                cout<<"A vector of float was created successfully.\n";
                operations<float>();
                    goto hh;

            break;
            }
        case '5':
            {
               cout<<"A vector of students was created successfully.\n";
                FciVector<students> x;

                there:cout<<"What kind of operation would you like to perform?\n"
        <<"1. Add element.\n2. Remove last element.\n3. Insert element at certain position.\n"
        <<"4. Erase element from a certain position.\n5. Clear.\n6. Display first element.\n"
        <<"7. Display last element.\n8. Display element at certain position.\n"
        <<"9. Display vector size.\n10. Display vector capacity.\n11. Is empty?\n";
        int choice,n;students k;courses y;
        cin>>choice;
        switch(choice)
        {
        case 1 :
            {
            cout<<"How many students you would like to add?\n";
            cin>>n;
            for(int i=0;i<n;i++)
            {

                k.store();
                x.Insert(x.getsize(),k);

                cout<<"enter number of courses : ";
                int w;cin>>w;
                for(int m=0;m<w;m++)
                {
                    y.add();

                x[x.getsize()-1].course.Insert(m,y);

                }
            }
                        cout<<"add successfully\n";

            break;}
            case 2 :
            {
                if(x.getsize()>0)
                x.Erase(x.getsize()-1);
                else
                {
                    cout<<"does not exist any elements\n";
                    goto there;
                }
                cout<<"remove successfully\n";

            break;}
            case 3 :
            {
                cout<<"Enter index start from 1\n";
                cin>>n;
                if(n>0 &&n<=x.getsize())
                {

                    x.Insert(n-1,k);
                    x[n-1].store();
                cout<<"enter number of courses : ";
                int w;cin>>w;
                for(int m=0;m<w;m++)
                {
                y.add();
                x[n-1].course.Insert(m,y);

                }

                    cout<<"insert successfully.\n";
                }
                else
                {
                    cout<<"not found\n ";
                    goto there;
                }

            break;}
            case 4:
            {
                cout<<"Enter index start from 1\n";
                cin>>n;
                if(n>0 &&n<=x.getsize())
                {
                  x.Erase(n-1);
                  cout<<"erase successfully.\n";
                }
                else
                {
                    cout<<"not found\n ";
                    goto there;
                }
            break;}
            case 5 :
            {
                    x.Clear();
                    cout<<"clear successfully.\n";
            break;}
            case 6:
            {
                if(x.getsize()>0)
               {
                    k=x.Front();
                k.printInfo();
                //y=k.course.Front();
                y.printCourseInfo();

               }
               else
                    {
                    cout<<"does not exist any elements\n";
                    goto there;
                }
            break;}
            case  7 :
            {
                if(x.getsize()>0)
               {

                k=x.Back();
                k.printInfo();
                k.course[0].printCourseInfo();

               }
               else
                    {
                    cout<<"does not exist any elements\n";
                    goto there;
                }

            break;}
            case 8 :
            {
                cout<<"Enter index start from 1\n";
                cin>>n;
                if( n>0 && n<=x.getsize())
                {
                  x[n-1].printInfo();
                  x[n-1].course[0].printCourseInfo();
                }
                else
                {
                    cout<<"not found\n ";
                    goto there;
                }

            break;}
            case  9 :
            {
                    cout<<"vector size :  "<<x.getsize()<<endl;
            break;}
            case 10 :
            {
                cout<<"vector capacity :  "<<x.getcapacity()<<endl;
            break;}
            case  11 :
            {
                cout<<(x.isempty()==1?"Yes this vector empty\n":"no this vector not empty\n");

            break;}
            default:
            {
                cout<<"invalid choice!!!\n";
            break;}
        }
        h: cout<<"Would you like to perform other operations? (Y/N)\n";
        char c;
        cin>>c;
        if(c=='Y'||c=='y')
            goto there;
        else if(c!='N' && c!='n')
        {
            cout<<"invalid input\n";
            goto h;
        }
        else{}


                    goto hh;

            break;
            }
        case '6':
            {

            break;
            }
         default:{
             cout<<"invalid choice !!!!" ; goto hh;
               break; }

}



    return 0;
}
