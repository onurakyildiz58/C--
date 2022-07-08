//onur akyıldız 191307026

#include <iostream>
using namespace std;

struct tree 
{
	int veri;
	struct tree* sol = NULL;
	struct tree* sağ = NULL;
	tree(int veri) 
	{
		this->veri = veri;
	}
};

void postorder(struct tree* tree)//soldan başla sağa geç köke uğra yazdır
{
	if (tree==NULL)
	{		
		return;
	}
	postorder(tree->sol);
	postorder(tree->sağ);
	cout << tree->veri << "  ";
}

void preorder(struct tree* tree)//kökten başla sola git sağa git yazdır
{
	if (tree == NULL)
	{		
		return;
	}
	cout << tree->veri << "  ";
	preorder(tree->sol);
	preorder(tree->sağ);
}

void inorder(struct tree* tree)//sola git köke uğra sağa geç yazdır
{
	if (tree == NULL)
	{		
		return;
	}
	inorder(tree->sol);
	cout << tree->veri << "  ";
	inorder(tree->sağ);
}


int main()
{
	setlocale(LC_ALL, "turkish");
	//elemanları atadık
	struct tree* kök = new tree(1);//köke aadığımız eleman                1
	kök->sol = new tree(2);//sol kökten sonraki ilk eleman             2     3
	kök->sağ = new tree(3);// sağ kökten sonraki ilk eleman             4   5
	kök->sol->sağ = new tree(4);//solun solundaki eleman
	kök->sağ->sol = new tree(5);// sağın solundaki eleman
	//sonuçta beşgen şeklini alıcak 


	cout << "preorder ile yazdırma : ";
	preorder(kök);
	cout << endl;

	cout << "inorder ile yazdırma : ";
	inorder(kök);
	cout << endl;

	cout << "postorder ile yazdırma : ";
	postorder(kök);
	cout << endl;

	

	return 0;
}
