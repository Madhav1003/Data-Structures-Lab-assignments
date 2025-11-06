int parity(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

Node* removeEvenParityNodes_CLL(Node* head) {
    if (!head) return NULL;

    Node* curr = head;
    Node* prev = NULL;

    do {
        if (parity(curr->data) % 2 == 0) {
            if (curr == head) {
                Node* last = head;
                while (last->next != head)
                    last = last->next;
                if (last == head) {
                    delete head;
                    return NULL;
                }

                head = head->next;
                last->next = head;
                Node* temp = curr;
                curr = head;
                delete temp;
            } else {
                prev->next = curr->next;
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    } while (curr != head);
return head;
}


Node* removeEvenParityNodes_DLL(Node* head) {
    if (!head) return NULL;

    Node* curr = head;

    while (curr) {
        Node* nextNode = curr->next;

        if (parity(curr->data) % 2 == 0) { 
            if (curr == head) {
                head = curr->next;
                if (head) head->prev = NULL;
                delete curr;
            }
            else {
                if (curr->prev) curr->prev->next = curr->next;
                if (curr->next) curr->next->prev = curr->prev;
                delete curr;
            }
        }

        curr = nextNode;
    }

    return head;
}
