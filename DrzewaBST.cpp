#include <iostream>


using namespace std;

struct drzewoBST
{
	drzewoBST* up;
	drzewoBST* left;
	drzewoBST* right;
	int val;
};

void printBT(const std::string& prefix, const drzewoBST* node, bool isLeft)
{
	if (node != NULL) // wypisuje gdi nie ma pustego miejsca
	{
		std::cout << prefix; // tego nie musi byæ, u nas prefix to jest na wstêpie pusty znak ""

		std::cout << (isLeft ? "+--" : "+--");

		// print the value of the node
		std::cout << node->val << std::endl;

		// enter the next tree level - left and right branch - rekurencja
		printBT(prefix + (isLeft ? "|   " : "    "), node->left, true);
		printBT(prefix + (isLeft ? "|   " : "    "), node->right, false);
	}
}

void printBT(const drzewoBST* node)
{
	printBT("", node, false);
}
void AddBstNode(drzewoBST*& root, int x, drzewoBST* root2 = NULL)
{
	if (root == NULL)
	{
		drzewoBST* w = new drzewoBST();
		w->up = root2;
		w->left = NULL;
		w->right = NULL;
		w->val = x;
		root = w;
	}
	else
	{
		if (x >= root->val)
		{
			AddBstNode(root->right, x, root);
		}
		else
		{
			AddBstNode(root->left, x, root);
		}
	}
}
//funkcja szukania inorder

void szukaj(drzewoBST* root, int x)
{
	drzewoBST* p = root;
	while (1)
	{
		if (p == NULL)
		{
			cout << "Brak wartosci do wyszukania";
			return;
		}
		if (p->val == x)
		{
			cout << "Wartosc znaleziona";
			return;
		}
		else if (x >= p->val)
		{
			p = p->right;
		}
		else if (x <= root->val)
		{
			p = p->left;
		}
		else
		{
			cout << "Nie znalezniono wartosci";
		}
	}
}


//funkcja wyszukujaca rekurencyjnie

void szukaj2(drzewoBST* root, int x)
{

	if (root == NULL)
	{
		cout << "Brak wartosci do wyszukania";
	}
	else if (root->val == x)
	{
		cout << "Wartosc znaleziona";
		return;
	}
	else if (x >= root->val)
	{
		szukaj2(root->right, x);
		//cout<<"Znaleziono "<<x<<endl;

	}
	else if (x <= root->val)
	{
		szukaj2(root->left, x);
		//cout<<"Znaleziono "<<x<<endl;
	}
	else
	{
		cout << "Nie znalezniono wartosci";
	}

}

//Funkcja usuwająca liście

void del(drzewoBST*& root)
{

	drzewoBST* p = root;
	while (1)
	{

		if (p == NULL)
		{
			cout << "Brak wartości" << endl;
		}

		if (p->left == NULL && p->right == NULL)
		{
			delete p;
			cout << "Usunelo";
			return;

		}
		else if (p->left != NULL)
		{
			p = p->left;
		}
		else if (p->right != NULL)
		{
			p = p->right;
		}
	}

}

//funkcja min
drzewoBST* min(drzewoBST* root)
{
	drzewoBST* p = root;
	while (p->left != NULL)
	{
		p = p->left;
	}
	cout << p->val;
	return p;

}

//funkcja max
drzewoBST* max(drzewoBST* root)
{
	drzewoBST* p = root;
	while (p->right != NULL)
	{
		p = p->right;
	}

	cout << p->val << endl;
	return p;
}

//funkcja wyszukujaca poprzednika
drzewoBST* poprzednik(drzewoBST* root)
{
	drzewoBST* p = root->up;
	if (root != NULL)
	{
		if (root->left)
		{
			return max(root->left);
		}
		else
		{
			while (p && (root == p->left))
			{
				root = p;
				p = p->up;
			}
			return p;
		}
	}
	cout << root;
	return root;
}

//inorder

/*
drzewoBST* inorder(drzewoBST* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
}
*/
//funkcja wyszukujaca nastepnika
drzewoBST* nastepnik(drzewoBST* root)
{
	drzewoBST* p = root;
	if (p->right != NULL)
	{
		return min(p->right);
	}
	drzewoBST* e = p->up;
	while (e != NULL && p == e->right)
	{
		p = e;
		e = e->up;
	}
	return e;
}

//funkcja usuwająca węzeł
/*
drzewoBST* tree_delete(drzewoBST*& root, drzewoBST*& x)
{
	drzewoBST* p = root;

	//wyznaczenie wezla do usuniecia
	if (x->left == NULL || x->right == NULL)
	{
		p = x;
	}
	else
	{
		p = nastepnik(x);
	}

	//
	drzewoBST* e;
	if (p->left != NULL)
	{
		e = p->left;
	}
	else
	{
		e = p->right;
	}

	//usuniecie wezla
	if (e != NULL)
	{
		e->up = p->up;
	}
	if (p->up = NULL)
	{
		root = e;
	}
	else if (p = p->up->left)
	{
		p->up->left = e;
	}
	else
	{
		p->up->right = x;
	}
	if (p->val != x->val)
	{
		x = p;
	}
	return p;

	return p;

}

*/
//funkcja usuwająca węzeł

drzewoBST* delete_tree(drzewoBST* root, int x)
{
	if (root == NULL)
	{
		return root;
	}
	if (x < root->val)
	{
		root->left = delete_tree(root->left, x);
	}
	else if (x > root->val)
	{
		root->right = delete_tree(root->right, x);
	}
	else {
		// lisc
		if (root->left == NULL and root->right == NULL)
		{
			return NULL;
		}
		// jedno dziecko albo brak
		else if (root->left == NULL) 
		{
			drzewoBST* p = root->right;
			return p;
		}
		else if (root->right == NULL) 
		{
			drzewoBST* z = root->left;
			return z;

		}
		// dwoje dzieci
		drzewoBST* e = min(root->right);
		//inorder
		root->val = e->val;
		//usun inorder
		root->right = delete_tree(root->right, e->val);
	}
	return root;
}




//rotacja prawa
void prawa(drzewoBST*& root) //q=root
{
	drzewoBST* p = root->left;
	root->left = p->right;
	p->right = root;
	root = p;
}

//rotacja lewa
void lewa(drzewoBST*& root) //root=p
{
	drzewoBST* q = root->right; 
	root->right = q->left;
	//parent
	q->left = root;
	root = q;
	//q = root;

}
//rotacja obustronna ??????????????


/*
void del(drzewoBST*& root)
{
	if (root!=NULL)
	{

	}
}
*/

int main()
{
	drzewoBST* r = NULL;

	AddBstNode(r, 12);
	AddBstNode(r, 6);
	AddBstNode(r, -5);
	AddBstNode(r, 11);
	AddBstNode(r, 3);
	AddBstNode(r, 8);
	AddBstNode(r, 22);
	AddBstNode(r, 16);
	AddBstNode(r, 10);
	AddBstNode(r, 27);
	cout << "Drzewo binarne: " << endl;
	printBT(r);
	cout << endl;
	cout << "Wszystkie elementy:" << r->left->right->val-1 << endl;

	szukaj(r, 30);
	cout << endl;
	szukaj2(r, 8);
	cout << endl;

	//del(r);
	
	cout <<"Root: "<< r->right->up->val << endl;
	cout << "Wartosc maksymalna: ";
	max(r);
	cout << "Wartosc minimalna: ";
	min(r);
	cout << endl;
	cout << "Poprzednik roota: ";
	poprzednik(r);
	cout << "Nastepnik roota: ";
	nastepnik(r);
	cout << endl;
	delete_tree(r,11);
	cout << "Drzewo binarne po usunieciu wezla: " << endl;
	printBT(r);
	cout << endl;
	prawa(r);
	printBT(r);
	cout << endl;
	lewa(r);
	printBT(r);
	
	//printBT(r);


	return 0;
}
