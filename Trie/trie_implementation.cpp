#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
    public:
    
        bool isTerminal;
        int ct;
        TrieNode* children[26];
        
        TrieNode() {
            isTerminal = false;
            ct = 0;
            
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
};

class Trie {
    private:
        TrieNode* root;
        
        void print_util(TrieNode* r, vector<string>& ans, string& temp) {
            if (r->isTerminal == true) {
                ans.push_back(temp);
            }
            
            if (r == nullptr) return;
            
            for (int i = 0; i < 26; i++) {
                if (r->children[i] != nullptr) {
                    temp.push_back(i + 'a');
                    
                    print_util(r->children[i], ans, temp);
                    
                    temp.pop_back();
                }
            }
        }
        
        void printWithPrefix(TrieNode* r, vector<string>& ans, string& str, string& prefix) {
            if (r->isTerminal == true) {
                ans.push_back(prefix + str);
            }
            
            if (r == nullptr) return;
            
            for (int i = 0; i < 26; i++) {
                if (r->children[i] != nullptr) {
                    str.push_back(i + 'a');
                    
                    printWithPrefix(r->children[i], ans, str, prefix);
                    
                    str.pop_back();
                }
            }
        }
        
        bool startsWithPrefix_util(TrieNode* r) {
            if (r->isTerminal == true) {
                return true;
            }
            
            bool ans = false;
            
            for (int i = 0; i < 26; i++) {
                if (r->children[i] != nullptr) {
                    ans = ans || startsWithPrefix_util(r->children[i]);
                }
            }
            
            return ans;
        }
        
        void findLCP_util(TrieNode* r, string& ans) {
            // base case
            if (r->isTerminal == true) return;
    
            TrieNode* temp;
            char ch;
            
            if (r->ct == 1) {
                for (int i = 0; i < 26; i++) {
                    
                    if (r->children[i] != nullptr) {
                        ch = i + 'a';
                        temp = r->children[i];
                    }
                }
                ans.push_back(ch);
            }
            else {
                return;
            }
            
            findLCP_util(temp, ans);
        }
        
    public:
        Trie() {
            root = new TrieNode();
        }
        
        void insert(string word) {
            TrieNode* temp = root;
            
            for (char& ch : word) {
                int i = ch - 'a';
                
                if (temp->children[i] == nullptr) {
                    temp->ct++;
                    temp->children[i] = new TrieNode();
                }
                
                temp = temp->children[i];
            }
            
            temp->isTerminal = true;
        }
        
        bool search(string word) {
            TrieNode* temp = root;
            
            for (char& ch : word) {
                int i = ch - 'a';
                
                if (temp->children[i] == nullptr) {
                    return false;
                }
                temp = temp->children[i];
            }
            
            return temp->isTerminal;
        }
        
        void deleteWord(string word) {
            TrieNode* temp = root;
            
            for (char& ch : word) {
                int i = ch - 'a';
                
                if (temp->children[i] == nullptr) {
                    return;
                }
                temp = temp->children[i];
            }
            
            temp->isTerminal = false;
        }
        
        vector<string> printAll() {
            vector<string> ans;
            string temp = "";
            
            print_util(root, ans, temp);
            
            return ans;
        }
        
        bool startsWithPrefix(string prefix) {
            TrieNode* temp = root;
            
            for (char ch : prefix) {
                int i = ch - 'a';
                if (temp->children[i]) {
                    temp = temp->children[i];
                }
                else {
                    return false;
                }
            }
            
            return startsWithPrefix_util(temp);
        }
        
        vector<string> printAllStartsWith(string prefix) {
            vector<string> ans;
            
            // go to that prefix first
            TrieNode* temp = root;
            for (char& ch : prefix) {
                int i = ch - 'a';
                
                if (temp->children[i] != nullptr) {
                    temp = temp->children[i];
                }
                else {
                    return ans;
                }
            }
            
            // printAll
            string str = "";
            printWithPrefix(temp, ans, str, prefix);
            
            return ans;
        }
        
        void findLCP(string& ans) {
            findLCP_util(root, ans);
        }
};

int main() {
    Trie t;
    
    // ______________________insert word ___________________
    t.insert("love");
    t.insert("lover");
    t.insert("lovely");
    t.insert("lov");
    t.insert("lofe");
    t.insert("joke");
    t.insert("joker");
    t.insert("joking");
    t.insert("jerk");
    t.insert("jerrkk");
    t.insert("jkr");
    
    // ______________search / delete word____________________
    cout << t.search("jerk") << endl;
    t.deleteWord("jerk");
    cout << t.search("jerk") << endl;
    
    // _____________print all words_____________________
    vector<string> str = t.printAll();
    for (auto s : str) {
        cout << s << ", ";
    }
    cout << endl;
    
    // ______________check if word starts with given prefix _____________________
    string prefix = "je";
    cout << "starts with: " << t.startsWithPrefix(prefix) << endl;
    
    // _____________print all word starts with given prefix______________________
    string prefix2 = "jok";
    vector<string> ans = t.printAllStartsWith(prefix2);
    for (auto s : ans) {
        cout << s << ", ";
    }
    cout << endl;
    
    // _____________ longest common prefix ______________________
    string common = "";
    t.findLCP(common);
    
    cout << "length of longest common prefix: " << common.size() << endl;
    cout << "print longest common prefix: " << common << endl;

    return 0;
}