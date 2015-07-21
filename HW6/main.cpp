#include <iostream>
#include <stack>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

class BTreeNode
{
	public:
		char Data;
		BTreeNode *Lchild;
		BTreeNode *Rchild;
};

class QTreeNode
{
	public:
		char Data;
		QTreeNode *child1;
		QTreeNode *child2;
		QTreeNode *child3;
		QTreeNode *child4;
};

bool get_words(char * file_name, vector<string> &w, char type);
bool get_reads(char * file_name, vector<string> &r, char type);
bool write_vector_to_screen(vector<string> v);
bool write_vector_to_file(vector<string> v, char * file_name);

class BinaryTree
{
public:
    BTreeNode *Root;
    BinaryTree(){Root = NULL;}
    bool insert_vector(vector<string> &w);
    bool compare_vector_to_tree(vector<string>&v);
};
class QuarternaryTree //created a class for the quarternary tree
{
public:
    QTreeNode *Root;
    QuarternaryTree(){Root = NULL;}
    bool insert_vector(vector<string> &w); // used address to find pointer
    bool compare_vector_to_tree(vector<string> &v);

    ~QuarternaryTree() { clearing(); delete Root; } // deleting the trees recursively.
    void clearing()
    { recursive_delete(Root);}//for deleting recursive and passed root
    void recursive_delete(QTreeNode* node)
    {
        if (node==NULL) // checking if the nodes are null, then going on to recursive delete.
        {
            recursive_delete(node->child1);
            recursive_delete(node->child2);
            recursive_delete(node->child3);
            recursive_delete(node->child4);
            deleteNode(node);
        }
    }
    void deleteNode(QTreeNode* node) // deletes nodes
    {
        delete node;
        node = NULL;
    }
};
bool BinaryTree:: insert_vector(vector<string> &w)
{
    for (int i = 0; i<w.size(); i++) //increment through each string in vector
    {
        string temp = w[i];          //string to work with
        BTreeNode *currentNode = Root;  //this will be the pointer that navigates through the tree
        for (int n=0; n<temp.size(); n++)
        {
            if (Root == NULL)
            {
                Root = new BTreeNode(); //create new BTreeNode, give it's data a value of z because this will differentiate it
                Root->Data = 'z';
                Root->Lchild = NULL;
                Root->Rchild = NULL;
                currentNode = Root;
            }
            if (temp[n] == 'y')
            {
                if (currentNode->Lchild == NULL)  //if the value is not yet in the tree then create new node
                {
                    currentNode->Lchild = new BTreeNode();
                    currentNode->Lchild->Data = 'y';
                    currentNode->Lchild->Lchild = NULL;
                    currentNode->Lchild->Rchild = NULL;
                }
                currentNode = currentNode->Lchild; //make sure to move down the tree
            }
           else if (temp[n] == 'r')
            {
                if (currentNode->Rchild == NULL)  //if the value is not yet in the tree then create new node
                {
                    currentNode->Rchild = new BTreeNode();
                    currentNode->Rchild->Data= 'r';
                    currentNode->Rchild->Lchild=NULL;
                    currentNode->Rchild->Rchild=NULL;
                }
                currentNode=currentNode->Rchild; //making sure to move down the tree
            }
        }
    }
    return true;
}
bool QuarternaryTree:: insert_vector(vector<string> &w)
{
    for (int i = 0; i<w.size(); i++) //increment through each string in vector
    {
        string temp = w[i];          //string to work with
        QTreeNode *currentNode = Root;  //this will be the pointer that navigates through the tree
        for (int n=0; n<temp.size(); n++)
        {
            if (Root == NULL)
            {
                Root = new QTreeNode(); //create new BTreeNode, give it's data a value of z because this will differentiate it
                Root->Data = 'z';
                Root->child1 = NULL;
                Root->child2 = NULL;
                Root->child3 = NULL;
                Root->child4 = NULL;
                currentNode = Root;
            }
            if (temp[n] == 'a')
            {
                if (currentNode->child1 == NULL)  //if the value is not yet in the tree then create new node
                {
                    currentNode->child1 = new QTreeNode();
                    currentNode->child1->Data = 'a';
                    currentNode->child1->child1 = NULL;
                    currentNode->child1->child2 = NULL;
                    currentNode->child1->child3 = NULL;
                    currentNode->child1->child4 = NULL;
                }
                currentNode = currentNode->child1; //make sure to move down the tree
            }
           if (temp[n] == 't')
            {
                if (currentNode->child2 == NULL)  //if the value is not yet in the tree then create new node
                {
                    currentNode->child2 = new QTreeNode();
                    currentNode->child2->Data = 't';
                    currentNode->child2->child1 = NULL;
                    currentNode->child2->child2 = NULL;
                    currentNode->child2->child3 = NULL;
                    currentNode->child2->child4 = NULL;
                }
                currentNode = currentNode->child2; //make sure to move down the tree
            }
            if (temp[n] == 'c')
            {
                if (currentNode->child3 == NULL)  //if the value is not yet in the tree then create new node
                {
                    currentNode->child3 = new QTreeNode();
                    currentNode->child3->Data = 'c';
                    currentNode->child3->child1 = NULL;
                    currentNode->child3->child2 = NULL;
                    currentNode->child3->child3 = NULL;
                    currentNode->child3->child4 = NULL;
                }
                currentNode = currentNode->child3; //make sure to move down the tree
            }
            if (temp[n] == 'g')
            {
                if (currentNode->child4 == NULL)  //if the value is not yet in the tree then create new node
                {
                    currentNode->child4 = new QTreeNode();
                    currentNode->child4->Data = 'g';
                    currentNode->child4->child1 = NULL;
                    currentNode->child4->child2 = NULL;
                    currentNode->child4->child3 = NULL;
                    currentNode->child4->child4 = NULL;
                }
                currentNode = currentNode->child4; //make sure to move down the tree
            }
        }
        currentNode->child1 = NULL;  //double checking to make sure that currentnode will point to nothing
        currentNode->child2 = NULL;
        currentNode->child3 = NULL;
        currentNode->child4 = NULL;
    }
    return true;
}
bool QuarternaryTree:: compare_vector_to_tree(vector<string> &v)
{
    ofstream out;
    char * file1 = "QReads_map_results.txt";
    out.open(file1);
    int stringcount = 0;  //will keep track of how many strings we've gone through to print to file
    int truthcount = 0;   //will keep track of how many strings match from reads.txt to my tree
    for (int i = 0; i<v.size(); i++)
    {
        string temp = v[i];  //using string for comparison
        bool flag = true;    //will help keep track of what's in the tree and what's not
        QTreeNode *currentNode = this->Root;  //using the Root from this binary tree
        for (int n = 0; n<10; n++) //only ten letters in each string
        {
            if (temp[n] == 'a')  //if the letter is a
            {
                if (currentNode->child1 != NULL && currentNode->child1->Data == temp[n]){ currentNode = currentNode->child1;}
                else { flag = false; break;}//if a then it will move down the tree
            }
            else if (temp[n] == 't') //if the letter is t,
            {
                if (currentNode->child2 != NULL && currentNode->child2->Data == temp[n]) {currentNode = currentNode->child2;}
                //if the Lchild is not NULL AND the Rchild's data is r then move on (double checking)
                else { flag = false; break;} //else make the flag false, break for loop
            }
            else if (temp[n] == 'c')// if the letter is c
            {
                if (currentNode->child3 != NULL && currentNode->child3->Data == temp[n]) {currentNode = currentNode->child3;}
                else {flag = false; break;}//if the letter is c then it will move down the tree
            }
            else if (temp[n] == 'g')
            {
                if (currentNode->child4 != NULL && currentNode->child4->Data == temp[n]) {currentNode = currentNode->child4;}
                else {flag = false; break;}
            }
            else {flag = false; break;}
        }
        stringcount++;//incrementing the amount of strings counted for comparison
        if (flag == true)
        {
            truthcount++;
            cout << "String " << i+1 << ": is Mapped." <<endl;
            out << "String " << i+1 << ": is Mapped." <<endl;
        }
        else if (flag == false){
            cout << "String " << i+1 << ": is not Mapped."<<endl;
            out << "String " << i+1 << ": is not Mapped."<<endl;
        }
    }
    cout << "Total QTree that reads: " << stringcount << endl;
    out << "Total QTree that reads: " << stringcount << endl;
    cout << "Total QTree reads mapped: " << truthcount << endl;
    out <<"Total QTree reads mapped: " << truthcount<<endl;
    out.clear(); out.close();
    return true;
}
bool BinaryTree:: compare_vector_to_tree (vector<string> &v) // this will compare the vector to the tree that we made and will read yes if they do
{
    ofstream out;
    char * file1 = "BReads_map_results.txt";
    out.open(file1);
    int stringcount = 0;  //will keep track of how many strings we've gone through to print to file
    int truthcount = 0;   //will keep track of how many strings match from reads.txt to my tree
    for (int i = 0; i<v.size(); i++)
    {
        string temp = v[i];  //using string for comparison
        bool flag = true;    //will help keep track of what's in the tree and what's not
        BTreeNode *currentNode = this->Root;  //using the Root from this binary tree
        for (int n = 0; n<10; n++) //only ten letters in each string
        {
            cout << temp[n];  //printing to console each character
            if (temp[n] == 'r')  //if the letter is r
            {
                if (currentNode->Rchild != NULL && currentNode->Rchild->Data == temp[n]){ currentNode = currentNode->Rchild;}
                //if the Rchild is not NULL, AND the Rchild's data is r then move on (double checking)
                else { flag = false; break;} //else make the flag false, break for loop
            }
            else if (temp[n] == 'y') //if the letter is y,
            {
                if (currentNode->Lchild != NULL && currentNode->Lchild->Data == temp[n]) {currentNode = currentNode->Lchild;}
                //if the Lchild is not NULL AND the Rchild's data is r then move on (double checking)
                else { flag = false; break;} //else make the flag false, break for loop
            }
            else {flag = false; break;}
        }
        stringcount++;
        if (flag == true)
        {
            truthcount++;
            cout << endl << "String " << i << ": is mapped." <<endl;
        }
        else if (flag == false){ cout << "String " << i << ": is not mapped."<<endl;}
    }
    cout << "Total that has been read: " << stringcount << endl;
    out << "Total that has been read: " << stringcount << endl;
    cout << "Total that is mapped: " << truthcount << endl;
    out <<"Total that is mapped: " << truthcount<<endl;
    out.clear(); out.close();
}
int main()
{
    vector<string> words;
    vector<string> words1;
    char *genome_file_name="genome_file.txt";          //make certain to place this file in the correct folder. Do not change path.
    if(!get_words(genome_file_name,words,'B'))          //if not get words because get words is different
        return 1;
    if(!get_words(genome_file_name,words1,'Q'))
        return 1;

    //1. Create a tree based on either BTreeNode or QTreeNode --> transforming the vector of words into the tree
    BinaryTree BGenomeTree;
    QuarternaryTree QGenomeTree;
    BGenomeTree.insert_vector(words);
    QGenomeTree.insert_vector(words1);
    //2. Read in file BReads or QReads using function get_reads(read_file_name,reads);
    vector<string> reads1;
    vector<string> reads2;
    char * reads_file_name="test_file.txt";                 //make certain to place this file in the correct folder. Do not change path.
    if(!get_reads(reads_file_name,reads1, 'B'))          //if doing QTreeNode, pass in 'Q'
        return 1;
    if(!get_reads(reads_file_name,reads2, 'Q'))
        return 1;

    //3. for each read, map it through the tree. If it follows a path in the tree, this read belongs to this genome. Write out a file named "BReads_map_results.txt" or "QReads_map_results.txt" listing each read and "Yes" or "No" if it does or doesn't map to the genome.
 cout << endl;
    cout<<"--------------------------------------------------------------" <<endl;
    cout<<"----------------------BINARY TREE MAPPING---------------------" <<endl;
    cout<<"--------------------------------------------------------------"<<endl;
   BGenomeTree.compare_vector_to_tree(reads1);
   cout<<"--------------------------------------------------------------" <<endl;
    cout<<"----------------------BINARY TREE ENDED---------------------" <<endl;
    cout<<"--------------------------------------------------------------"<<endl;
    cout<<endl;
    cout << endl;
    cout<<"--------------------------------------------------------------" <<endl;
    cout<<"----------------------QUATERNARY TREE MAPPING---------------------" <<endl;
    cout<<"--------------------------------------------------------------"<<endl;
    QGenomeTree.compare_vector_to_tree(reads2);
    cout<<"--------------------------------------------------------------" <<endl;
    cout<<"----------------------QUATERNARY TREE ENDED. QUIT---------------------" <<endl;
    cout<<"--------------------------------------------------------------"<<endl;
    BGenomeTree.~BinaryTree();
    QGenomeTree.~QuarternaryTree();

}


/*******************************************************************************
This function takes the genome file name to read and reads all overlapping
words of size 10 that are present in the file and stores each word in a vector.
The vector is passed to this function as a parameter -- by reference such
that the calling function has access to the vector of words.
Type='B' means you are doing a binary tree. Type='Q' means you are doing
the quartenary tree. This function will translate the file such that the
same file can be used for either tree.
*******************************************************************************/
bool get_words(char * file_name, vector<string> &w, char type)
{
    int i,j;
    int len=0;
    ifstream in;
    in.open(file_name);
    if(!in.is_open()) {cout << "The genome file could not be opened. Check the location.\t"; return false;}

    char * word=new char [11];                              //this is a default, we'll be looking at words of size 10
    while(in.peek()!=EOF) {in>>word[0]; len++;}             //gets the length of the sequence
    in.clear(); in.close(); in.open(file_name);             //have to close and reopen file to reset filestream to beginning of file

    for(i=0; i<10; i++)
    {
        in>> word[i];
        if(word[i]<97) word[i]+=32;     //makes it lowercase
        if(type=='B' || type=='b')      //if doing BTree, translates 4 letter code into two letter code
        {
            if(word[i]=='a' || word[i]== 'g') word[i]='r';  //purine
            else word[i]='y';   //pyrimidine
        }

    }
    word[10]='\0';
    w.push_back(word);
    for(i=1; i<(len-10-1); i++)   //read until the end of the file
    {
        //shift
        for(j=0; j<9; j++) word[j]=word[j+1];
        in>> word[9];
        if(word[9]<97) word[9]+=32;     //makes it lowercase
        if(type=='B' || type=='b')
        {
            if(word[9]=='a' || word[9]== 'g') word[9]='r';  //purine
            else word[9]='y';   //pyrimidine
        }
        word[10]='\0';
        //strcpy(w[i],word);
        cout << i << "\t" << word << endl; cout.flush();
       w.push_back(word);
    }
    in.clear(); in.close();

    return true;
}

/*******************************************************************************
This function takes the reads file name to read and reads each individual word
in the file and stores each word in a vector.
The vector is passed to this function as a parameter -- by reference such
that the calling function has access to the vector of words.
Type='B' means you are doing a binary tree. Type='Q' means you are doing
the quartenary tree. This function will translate the file such that the
same file can be used for either tree.
*******************************************************************************/
bool get_reads(char * file_name, vector<string> &r, char type)
{
    int i;
    ifstream in;
    in.open(file_name);
    if(!in.is_open()) {cout << "The read file could not be opened. Check the location.\t"; return false;}

    char * word=new char [20];                              //this is a default, we'll be looking at words of size 10

    while(in.peek()!=EOF)
    {
        in.getline(word,20,'\n');
        for(i=0; i<10; i++) {if(word[i]<97) word[i]+=32;}     //makes it lowercase
        if(type=='B' || type=='b')      //if doing BTree, translates 4 letter code into two letter code
        {
            for(i=0; i<10; i++)
            {
                if(word[i]=='a' || word[i]== 'g') word[i]='r';  //purine
                else word[i]='y';   //pyrimidine
            }
        }
        r.push_back(word);
    }
    in.clear(); in.close();
    delete word;
    return true;
}

bool write_vector_to_screen(vector<string> v)
{
    int i;
    for(i=0; i<v.size(); i++)
        cout << v[i] << endl;
    return true;
}

bool write_vector_to_file(vector<string> v, char * file_name)
{
    ofstream out;
    out.open(file_name);
    int i;
    for(i=0; i<v.size(); i++)
        out << v[i] << endl;
    out.clear();
    out.close();
    return true;
}
