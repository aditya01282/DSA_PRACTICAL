#include<iostream>
#include<string>
using namespace std;
class dictionary;
class avlnode
{
	string keyword;
	string meaning;
	avlnode *left,*right;
	int bf;
	public:
	avlnode()
	{
		keyword='\0';
		meaning='\0';
		left=right=NULL;
		bf=0;
	}
	avlnode(string k,string m)
	{
		keyword=k;
		meaning=m;
		left=right=NULL;
		bf=0;
	}
friend class dictionary;
};

class dictionary
{
	avlnode *par,*loc;
	public:
	avlnode *root;
	dictionary()
	{
		root=NULL;
		par=loc=NULL;
	}
	void accept();
	void insert(string key,string mean);
	void LLrotation(avlnode*,avlnode*);

	void RRrotation(avlnode*,avlnode*);

	void inorder(avlnode *root);
	void deletekey(string key);
	void descending(avlnode *);
	void search(string);
	void update(string,string);

};
void dictionary::descending(avlnode *root)
{
	if(root)
	{
		descending(root->right);
		cout<<root->keyword<<" "<<root->meaning<<endl;
		descending(root->left);
	}
}

void dictionary::accept()
{
	string key,mean;
	cout<<"Enter keyword "<<endl;
	cin>>key;
	cout<<"Enter meaning "<<endl;
	cin>>mean;
	insert(key,mean);
}
void dictionary::LLrotation(avlnode *a,avlnode *b)
{
	cout<<"LL rotation"<<endl;
	a->left=b->right;
	b->right=a;
	a->bf=b->bf=0;
}

void dictionary::RRrotation(avlnode *a,avlnode *b)
{
	cout<<"RR rotation"<<endl;
	a->right=b->left;
	b->left=a;
	a->bf=b->bf=0;
}

