class Solution {
public:
    struct TrieNode
    {
      bool endsHere; //you can also use a bool
        TrieNode* child[26];
    };
    
    TrieNode* getNode()
    {
        TrieNode* newNode=new TrieNode;
        newNode->endsHere=0;
        for(int i=0;i<26;i++)
            newNode->child[i]=NULL;
        return newNode;
    }
    
    TrieNode* root=getNode();
    
    string replaceWords(vector<string>& dictionary, string sentence) 
    {
        if(sentence.length()==1) //no prefix can be made again
            return sentence;
        insertWords(dictionary);
        return replaceHelper(sentence);
    
    }
    void insertWords(vector<string>& words)
    {
       
        for(int i=0;i<words.size();i++)
        {
             TrieNode* curr=root; //start inserting from root
            for(int j=0;j<words[i].length();++j)
            {
                int ind=words[i][j]-'a';
                if(curr->child[ind]==NULL) //create a new TrieNode
                    curr->child[ind]=getNode() ; 
                curr=curr->child[ind];
            }
            //since word ends 
            curr->endsHere=1;
        }
    }
    string replaceHelper(string s)
    {
        string res="";
        int j=0;
        int len=s.length();
        while(j<len)
        {
            if(s[j]==' ')
            {
                //add it to res
                res+=' ';
                j++;
            }
            else{
                //get the word
                string str="";
                while(j<len && s[j]!=' ')
                {
                    str+=s[j]; j++;
                }
                //check if it is in the trie
                string s=checkTrie(str);
                res+= (s!="") ? s : str; 
            }
        }
        return res;
    }
    
    string checkTrie(string word){
        string temp="";
        TrieNode* curr=root;
        for(int i=0;i<word.length();i++)
        {
            temp.push_back(word[i]);
            if(curr->child[word[i]-'a']==NULL)
                return "";
            if(curr->child[word[i]-'a']->endsHere>0)
                return temp;
            curr=curr->child[word[i]-'a'];
        }
        return temp;
    }
};