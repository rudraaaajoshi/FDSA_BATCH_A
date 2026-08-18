#include<iostream>
using namespace std;


int main(){
    int marks[50];
    int i,n,j,temp,key;

    cout<<"Enter the number of Students"<<endl;
    cin>>n;

    for(i=0;i<n;i++){
        cout<<"Enter marks of student "<<i+1<<endl;
        cin>>marks[i];
    }
    for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){

            temp=marks[i];
            if(marks[i]>marks[j]){
                marks[i]=marks[j];
                marks[j]=temp;
            }
            else{
                continue;
            }
            }
}
cout<<"selection"<<endl;
for (i=0;i<n;i++){
    cout<<marks[i]<<endl;
    }


    for(i=0;i<n-1;i++){
        for (j=0;j<n-i-1;j++){
            if(marks[j]>marks[j+1]){
                temp=marks[j];
                marks[j]=marks[j+1];
                marks[j+1]=temp;

            }

        }
    }
cout<<"bubble"<<endl;
    for (i=0;i<n;i++){
    cout<<marks[i]<<endl;
    }



    for(i=1;i<n;i++)
    {
        key=marks[i];
        j=i-1;

        while(j>=0 && marks[j]>key)
        {
            marks[j+1]=marks[j];
            j--;
        }

        marks[j+1]=key;
    }




cout<<"insertion"<<endl;
for (i=0;i<n;i++){
    cout<<marks[i]<<" ";
    }



}
