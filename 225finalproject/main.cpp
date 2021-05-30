//Parinda Rahman-1931804042-section 2 cse 225
#include <iostream>
#include <fstream>
#include <string>
#include<string.h>
#include <cstring>
#include <sstream>
#include<bits/stdc++.h>
#include "runarray.h"
#include "Unsortedtype.h"
#include "Unsortedtype.cpp"
using namespace std;

int main()
{

    UnsortedType<runarray>xlist;
    runarray* q;
    q=new runarray;
    int number;
    cout<<"Enter the number of players information you would like to access: "<<endl;//input for the number of players information to be accessed
    cin>>number;int countr=0;
    fstream file;
    string word,filename;string temp,temp1,temp2,temp3;string x;
    filename = "Players.txt";//Player.txt file initialised
    file.open(filename.c_str());//the file is opened
    while (file >> word && countr!=(number*3))//the loop continues till th end of the file and until the value of the counter is >number times 3
    {


        if(word=="Run:")
        {

            for(int i=0;i<10;i++)
            {
                file>>word;
                temp=word;
                if (i==9)
                {
                    x=temp.substr(0,temp.size());//used for the very last run as it has no comma
                }
                else
                {
                     x=temp.substr(0,temp.size()-1);//used to remove the comma
                }


                stringstream p(x);//converting string to int
                int y;
                p>>y;
                q->runArray[i]=y;//stored in an array of the object

            }
        }
        if(word=="Name:")//if the word Name is found then it takes in the next two names,last name and first name
        {
            file>>word;
            temp1=word;
            file>>word;
            temp2=word;

            temp1=temp1+" "+temp2;//string is concatenated
            q->name=temp1;


        }
        if(word=="ID:")// if "ID" is found the string is read
        {
            file>>word;
            temp3=word;
            stringstream p(temp3);
                int y;
                p>>y;
                q->id=y;


        }


        countr=countr+1;
        if (countr%3==0)
        {
            xlist.InsertItem(*q);//insertion into the link list
            q=new runarray;

        }

    }

    ofstream filep("Players-Summary.txt");//The new file is opened to be written on to

        if (!filep)
        {
            cout<<"File did not open"<<endl;
        }


        runarray* r = new runarray;
        xlist.ResetList();
        UnsortedType<runarray> ylist;
        for(int i=0; i<xlist.LengthIs();i++)
        {
            xlist.GetNextItem(*r);//the item is accessed from the first linked list and inserted to the next linked list
            ylist.InsertItem(*r);
        }
        ylist.ResetList();
        for (int i=0;i<ylist.LengthIs();i++)//The names ID these are being written on to the new file
        {

            ylist.GetNextItem(*r);
            filep<<"ID: ";
            filep<<r->id<<endl;
            filep<<"Name: ";
            filep<<r->name<<endl;

            filep<<"Total Run: ";
            filep<<r->findTotal()<<endl;//the findtotal() function is called from the runarray class
            filep<<"Average Run: ";
            filep<<r->findAverage()<<endl;//the findAverage() function is called from the runarray class
            filep<<"Maximum Run: ";
            filep<<r->findMax()<<endl;//the findMax() function is called from the runarray class
            filep<<"Minimum Run: ";
            filep<<r->findMin()<<endl;//the findMin() function is called from the runarray class



        }

    return 0;
}
