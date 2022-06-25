// 191307026 Onur Akyıldız

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
	if (tree == NULL)
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
int size(struct tree* tree)
{
	if (tree==NULL)
	{
		return 0;
	}
	else
	{
		return size(tree->sağ) + 1 + size(tree->sol);
	}
}
int yükseklik(struct tree* tree)
{
	if (tree == NULL)
	{
		return 0;
	}
	else
	{
		int sağyükseklik, solyükseklik;
		sağyükseklik = yükseklik(tree->sağ);
		solyükseklik = yükseklik(tree->sol);
		if (sağyükseklik > solyükseklik) 
		{
			return sağyükseklik + 1;
		}
		else
		{
			return solyükseklik + 1;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "turkish");
	struct tree* kök = new tree(27);

	kök->sol = new tree(18);
	kök->sağ = new tree(39);

	kök->sol->sol = new tree(14);
	kök->sol->sağ = new tree(22);
	kök->sağ->sol = new tree(29);
	kök->sağ->sağ = new tree(42);
	
    kök->sol->sol->sol = new tree(2);
	kök->sol->sol->sağ = new tree(17);
	kök->sol->sağ->sol = new tree(12);
	kök->sol->sağ->sağ = new tree(24);
	kök->sağ->sol->sağ = new tree(34);

	kök->sol->sol->sağ->sol = new tree(15);
	kök->sol->sağ->sağ->sol = new tree(23);

	cout << "preorder ile yazdırma : ";
	preorder(kök);
	cout << endl;

	cout << "inorder ile yazdırma : ";
	inorder(kök);
	cout << endl;

	cout << "postorder ile yazdırma : ";
	postorder(kök);
	cout << endl;

	cout << "ağaçtaki düğüm sayısı : " << size(kök) << endl;
	cout << "ağaçın yükseksiği : " << yükseklik(kök) << endl;


	return 0;
}