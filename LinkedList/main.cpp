#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    cout<<"1  dodaj element na poczatku";
    cout<<"\n2  dodaj element na koncu";
   	cout<<"\n3 dodaj element w œrodku";
	cout<<"\n4 usun element z pocz¹tku";
	cout<<"\n5 usun element z konca";
	cout<<"\n6 usun element z srodka";
	cout<<"\n7 pokaz liste ";
	cout<<"\n8 zlicz liczbe elementów";
	cout<<"\n9 wyszukaj element";

	cout<<"\n0 wyjdz z programu ";

	int choice,v,p;
	LinkedList ll;
	do {
		cout<<"\nwybierz operacje ktora mam wykonac: ";
		cin>>choice;
		switch (choice)
		{
			case 1:
				cout<<"wprowadz element: ";
				cin>>v;
				ll.insert_at_beginning(v);
				break;

			case 2:
				cout<<"wprowadz element: ";
				cin>>v;
				ll.insert_at_end(v);
				break;

			case 3:
				cout<<"wprowadz element: ";
				cin>>v;
				cout<<"wprowadz pozycje( zero-indexed ): ";
				cin>>p;
				ll.insert_at_given_position(v,p);
				break;

			case 4:
				ll.delete_at_beginning();
				break;

			case 5:
				ll.delete_at_end();
				break;

			case 6:
				cout<<"wprowadz pozycje( zero-indexed ): ";
				cin>>p;
				ll.delete_at_given_position(p);
				break;

			case 7:
				ll.print();
				break;
            case 8:
				cout<<"ilosc elementow to: "<<ll.getCount()<<endl;
				break;
            case 9:
				cout<<"wprowadz element do wyszukania: ";
				cin>>v;
				int p=ll.searchElement(v);
				if(p==-1)
                  cout<<"dany element nie jest na liscie"<<endl;
                else
                    cout<< "dany element jest na miejscu (zero-indexed):"<<p<<endl;
				break;

		}
	} while (choice != 0);

    return 0;
}
