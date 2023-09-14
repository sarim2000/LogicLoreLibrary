# basic function implementation of trie

```c++
# trie structure
struct Node{
    Node *links[26];
    int flag = 0;
}

class Trie{
    private:
        Node *root;
    public:
        void Trie(){
            root = new Node();
        }

        # i will be creating functions below so as to not make it seem too bloated/big
}


```


### trie insertion

1. insert

```
(root) ---inesert "tree"---> (root) t r e e --->insert "trie" ---> t r e e (i e will be added below 'r')
```        

trie starts from root then for insertion we check that if that on the current node that we are on have this word or not if not create a link to it

```c++

struct Node{
    # extending from above
    
    bool containWord(char ch){
        return links[ch - 'a'];
    }

    void putWord(char ch, Node *node){
        links[ch - 'a'] = node;
    }

    Node *getNode(char ch){
        return links[ch - 'a'];
    }
}

void insertWord(string word){
    # init node to root
    Node *node = root;

    for (int i = 0; i < word.length(); i++){
        if (!node->containWord(word[i])){
            node->putWord(word[i],new Node());
        }
        node = node->getNode(word[i]);
    }
}


```

2. isWordPresent

we will maintain a flag (boolean) and whenever we are at the end we will set this flag to true

```c++

struct Node{
    # extending from above
    bool flag = false;

    void setEnd(){
        flag = true;
    }
}

void insertWord(string word){
    # init node to root
    Node *node = root;

    for (int i = 0; i < word.length(); i++){
        if (!node->containWord(word[i])){
            node->putWord(word[i],new Node());
        }
        node = node->getNode(word[i]);
        node->setEnd(); 
    }
}

bool isWordPresent(string word){
     # init node to root
    Node *node = root;

    for (int i = 0; i < word.length(); i++){
        if (!node->containWord(word[i])){
            return false;
        }
        node = node->getNode(word[i]);
    }
    return node->flag;
}

```

3. startsWith

similar to the isWordPresent function here we will just go through each word and check whether we have a link to itor not and if we dont we just return false; after fully iterating return true

```c++

bool startsWith(string word){
    Node *node = root;
    for (int i = 0; i < word.length(); i++){
        if (!node->containWord(word[i])){
            return false;
        }
        node = node->getNode(word[i]);
    }
    return true;
}

```

