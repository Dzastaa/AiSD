#include <iostream>

using namespace std;

struct node
{int val;
node *next;
};

//Funkcja dodaj¹ca elementy do listy na pocz¹tek
void Addtolist(node *&H, int x) //przez & pozwalamy by head sie nam zmienil
{
	node *p=new node;
	p->val=x;
	p->next=H;
	H=p;
}

//Funkcja wypisuj¹ca elementy listy
void show(node *H)
{
	cout<<"H->";
	node *p=H;
	while(p!=NULL)
	{
		cout<<p->val<<"->";
		p=p->next; //chcemy zeby p pokazywalo na to co pokazuje p->next
	}
	cout<<"NULL"<<endl; 
}

//Funkcja usuwaj¹ca element z pocz¹tku listy
void Del(node*&H)
{
if(H!=NULL) //jezeli h jest rozne od null, czyli istniej¹ elementy
{
	node *p=H;
	H=p->next; //przesuwa nam dowiazania alt.H=H->next
	delete p; //usuwa to na co pokazuje head
	
}	
}

//Funkcja dodaj¹ca element na koñcu listy
void Addtoend(node *&H, int x)
{
	node *p=new node; //stworzona struktura
	p->val=x; //wstawiamy do niej x
	p->next=NULL; //na koncu wstawiamy nulla
	if(H==NULL)
	{
		H=p;
	}
	else
	{
		node *e=H;
		while(e->next!=NULL)
		{
			e=e->next;
		}
		e->next=p;
	}
}

//Funkcja usuwaj¹ca co drugi element na liscie
void second_del(node *&H) 
 {
 	if(H!=NULL && H->next!=NULL)
 	{
 		node *p=H;
 		while(p!=NULL && p->next !=NULL)
 		{
 			Del(p->next);
 			p=p->next;
		}
	 }
 }

//Funkcja kopiuj¹ca elementy na liœcie 2x
void kopia2x(node *H) 
{
	if(H!=NULL)
	{
		node *p=H;
		while(p!=NULL)
		{
			Addtolist(p->next, p->val);
			p=p->next->next;	
		}	
	}		
}

//Funkcja kopiuj¹ca i powielaj¹ca wartoœæ
void kopia_powiel(node *H)
{
	if(H!=NULL)
	{
		node *p=H;
		while(p!=NULL)
		{
			for(int i=1;i<p->val;i++)
			{
				Addtolist(p->next, p->val);
				p=p->next;	
			}
			p=p->next;
		}
	}
}

//Funkcja usuwaj¹ca element x
void Del_x(node *& H, int x)
 {
 	if(H!=NULL)
 	{
 		if(H->val==x)
 		{
 			Del(H);
		 }
		 else
		 {
		 	node*p=H;
		 	while(p->next!=NULL&&p->next->val!=x)
		 	p=p->next;
		 	if(p->next!=NULL)
			 {
			 	Del(p->next);	
			 }
		 }
	 }
 }
 
//Funkcja zamieniaj¹ca 1 element z 2 elementem miejscami - swap
void swap(node *& H)
 {
 	if(H!=NULL&&H->next!=NULL){
 	 node * p=H;
	 H=p->next;
	 p->next=H->next;
	 H->next=p;	
	 
	 }
 }


 
 //Funkcja zamieniaj¹ca x z nastêpnym elementem po nim
 void swap_x(node *&H, int x)
 {
 	if(H&&H->next){
 		if(H->val==x)
 		swap(H);
 		else
 		{
 			node *p=H;
 			while(p->next!=NULL&&p->next->val!=x)
		 	p=p->next;
		 	if(p->next&&p->next->next)
		 	{
		 		swap(p->next);
		 		/*
		 		node*e=p->next;
		 		p->next=e->next;
				e->next=e->next->next;
				p->next->next=e;
				*/
				
			 }
		 }
	 }
 }
 
 //Funkcja zamieniaj¹ca wartoœæ x z poprzedzaj¹cym elementem
 void swap_prev(node *&H, int x)
{
	if(H->val!=x)
	{
		if(H->next->val==x)
		{
 			swap(H);
 			return;
 		}
		node *p = H;
		while(p->next->val !=x && p->next != NULL )
		{
			p = p->next;
		}
		node *e = p->next; 
		p->next = p->next->next;
		e->next = p;
		node *s =H;
		while(s->next != e->next)
		{
			s = s->next;
		}
		s->next = e;
	}
	
}

//Funkcja zamieniaj¹ca pierwszy element z ostatnim na liœcie
void zamiana(node *&H)
{
	if(H!=NULL&&H->next!=NULL)
	{
		node *p=H;
		node *e=H;
		while(p->next->next!=NULL)
		{
			p=p->next;
		}
		e=p->next;
		e->next=H->next;
		p->next=H;
		H->next=NULL;
		H=e;
	
	}
}

//Funkcja zamieniaj¹ca co drugi element na liœcie
void swap_all(node *& H)
 {
 	if(H!=NULL&&H->next!=NULL){
 	node *p=H;
 	while(p!=NULL && p->next!=NULL)
 	{
 		swap(p->val,p->next->val);
 		p=p->next->next;
	 }
	}
 }
 
 //Funkcja kopiuj¹ca H->1->2->3 H2->3->2->1
 //H->1->2->3->3->2->1
 void copy(node *H)
 {
 	if(H)
	 {
		node *H2=NULL;
		node *p=H;
		while(p->next!=NULL)
		{
			Addtolist(H2, p->val);
			p=p->next;	
		} 	
		Addtolist(H2,p->val);
		p->next=H2;
		H2=NULL;
	 }	
 }
 
 // Funkcja która kopiowanie listy  w odwrotnej kolejnosci
//H2->NULL
 //H->1->2->NULL
 //Wynik:
 //H2->2->1->NULL
 //H->NULL
void zad1(node *&H)
{
	if(H)
	{
		node *H2=NULL;
		node *p=H;
		while(p!=NULL)
		{
			Addtolist(H2,p->val);
			p=p->next;
		}
	
		H=H2;
		H2=NULL;
		
	}
}
 
 //Funkcja usuwaj¹ca parzyste elementy z listy

void parzyste(node *&H)
{
	if(H!=NULL)
	{
		while(H->val%2==0)
		{
			Del(H);
		}
		node *p=H;
		while(p!=NULL&&p->next!=NULL)
		{
		
		while(p->next!=NULL&&p->next->val%2==0)
		{
		
				
			Del(p->next);
		}
			
		p=p->next;
		}	
	}
}

//Funkcja dziel¹ca listê na pó³ - zad2
void split(node* &H,node*&H1,node *&H2)
{
    if(!H) return;
    int counter = 0;
    node* p = H;
    while(p != NULL)
    {
        counter++;
        p= p->next;
    }
    p=H;
    for(int i = 0;i<(counter/2)-1;i++)
    {
        p=p->next;
    }
    H2 = p->next;
    p->next = NULL;
    H1 = H;
    H = NULL;

    
}



 
 //Funkcja dodaj¹ca elementy na koñcu
 void addtoend(node *&H, node *&T,int x)
 {
 	node *p=new node;
  	p->val=x;
 	p->next=NULL;
 	
 	if(H==NULL)
 	{
 		H=p;
 		T=p;
	 }
	 else
	 {
	 	T->next=p;
	 	T=p;
	 }
 }
 
 //2
 void addtoend2(node *&H, node *&T, node *P)
 {
 	node *p=H;
 	p->next=NULL;
 	if(H==NULL)
 	{
 		H=p;
 		T=p;
	}
	else
	{
		T->next=p;
	T=p;
	}
 }
 
 //Funkcja ³¹cz¹ca dwie listy i sortuj¹ca je
 void merge(node* &H1,node *&H2,node *&H)
{ node *p;
    node *T = H;
    while(H1 && H2)
    {
        if(H1->val < H2->val)
        {
            p = H1;
            H1 = H1->next;

            p->next=NULL;
            addtoend2(H,T,p);
            
        }
        else
        {
            p = H2;
            H2 = H2->next;

            p->next;
            addtoend2(H,T,p);
        }
    }
    while(!H1 && H2)
    {
       p = H2;
            H2 = H2->next;

            p->next;
            addtoend2(H,T,p);
    }
    while(!H2 && H1)
    {
        p = H1;
            H1 = H1->next;

            p->next;
            addtoend2(H,T,p);
    }
}

//Usuwanie z listy wszystkie elementy oprócz najwiêkszego na liœcie jednostronnie wi¹zanej
void usun(node*& H)
{
	int max = 0;
	node* p = H;

		while (p)
		{
		if (p->val > max)
		{
			max = p->val;
		}
	p = p->next;
	}
	
	p = H;

	while (H&&H->val !=max)
	{
		Del(H);
	}
	p = H;
	while (p->next)
	{
		H->next=NULL;
	}
}


//Funkcja przenosz¹ca elementy mniejsze od œredniej na koniec listy
void srednia(node*& H)
{
	node* p = H;
	int srednia = 0;
	int counter = 0;
	int suma = 0;

	if (H != NULL)
	{
		while (p!=NULL)
		{
			counter++;
			suma += p->val;
			p = p->next;
			
		}
			srednia=suma/counter;
		p=H;
	
	while(H&&H->val<srednia)
	{
		Addtoend(H,H->val);
		Del(H);
	}
	p=H;
	while(p->next&&p->next->val<srednia)
	{
		Addtoend(H,p->next->val);
		p->next=p->next->next;
		p=p->next;
	}

	}
}


int main()
{
	node *H=NULL;
	int x=5;
	cout<<H<<endl;
	Addtolist(H,5);
	Addtolist(H,2);
	Addtolist(H,-6);
	
	//wartosci -6->2->5
	cout<<H<<endl;
	cout<<H->val<<endl;
	cout<<H->next->val<<endl;
	cout<<H->next->next->val<<endl;
	
	show(H);
	
	Del(H);
	show(H);
	Addtolist(H->next,10);
	show(H);
	Del(H->next->next);
	show(H);
	Addtoend(H, 7);
	show(H);
	second_del(H);
	show(H);
	kopia2x(H);
	show(H);
	kopia_powiel(H);
	show(H);
	cout<<endl;
	node* H2 = NULL;
 	//Add(H2,1);
 	Addtolist(H2,1);
 	Addtolist(H2,5);
 	Addtolist(H2,10);
 	Addtolist(H2,11);
 	Addtolist(H2,13);

 	show(H2);
 	Del_x(H2,10);
 	show(H2);
 	swap(H2);
 	show(H2);
 	swap_x(H2, 11);
 	show(H2);
 	Addtolist(H2,14);
 	show(H2);
 	swap_prev(H2,13);
 	show(H2);
 	zamiana(H2);
 	show(H2);
 	swap_all(H2);
 	show(H2);
 	swap_x(H2, 5);
 	show(H2);
 	
 	node *H3=NULL;
 	Addtolist(H3,3);
 	Addtolist(H3,2);
 	Addtolist(H3,1);
 	
 	
 	copy(H3);
 	show(H3);
 	cout<<endl;
 	zad1(H3);
 	show(H3);
 	cout<<endl<<endl;
 	node *H4=NULL;
 	show(H2);
 	show(H3);
 	show(H4);
 //	merge(H4,H2,H3);
 	show(H2);
 	show(H3);
 	show(H4);
 	
 	
}
