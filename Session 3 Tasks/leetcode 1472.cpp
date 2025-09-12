class Node{
public:
    string url;
    Node* next;
    Node* prev;

    Node(string url){
        this->url = url;
        next = prev = nullptr;
    }
};

class BrowserHistory {
public:
    Node* currentPage;
    BrowserHistory(string homepage) {
        currentPage = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newPage = new Node(url);
        currentPage->next = newPage;
        newPage->prev = currentPage;
        currentPage = newPage;
    }
    
    string back(int steps) {
        while(currentPage->prev != nullptr && steps>0){
            currentPage = currentPage->prev;
            steps-=1;
        }

        return currentPage->url;
    }
    
    string forward(int steps) {
        while(currentPage->next != nullptr && steps>0){
            currentPage = currentPage->next;
            steps--;
        }

        return currentPage->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */