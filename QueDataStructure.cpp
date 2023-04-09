
#include <iostream>

//Simple way to check for logical errors in our code
#include <assert.h>

template <class ElementType>
class Queue {

    protected:
        ElementType *Data;  // Holds Data in the Queue
        const int MaxNum;   // Maximum number of Elements in the Queue
        int pos1, posn;     // Declaration for the beggining and end of the queue
        int ElementCount;   // Actual Number of Elements in the Queue

    public: 
    //Constructor from number of elemnents
        Queue(int MaxSize = 500) : MaxNum(MaxSize) {
            Data = new ElementType[MaxNum + 1];
            
            /*
                Starts with
                First position 0
                Current position 0
                ELementCount 0
            */
            pos1 = 0, posn = 0, ElementCount = 0; 
        }

    //Constructor from other Queue
        Queue(const Queue<ElementType> &OtherQueue) : MaxNum(OtherQueue.MaxNum){

            //Similar to previos constructor
            OtherQueue.pos1 = 0, OtherQueue.posn = 0, OtherQueue.ElementCount = 0; 

            //copy data from other que to new queue
            Data = new ElementType[MaxNum + 1];
            for (int i=0 ; i < MaxNum; i++) {
                Data[i] = OtherQueue.Data[i];
            }
        }

    // class destuctor
        ~Queue(void) {
            delete[] Data;
        }
        
    //Dunction to add elements to the front of the Queue
        void Enqueue(const ElementType &Item) {
            assert(ElementCount < MaxNum);

            Data[ posn++ ] = Item;
            ++ElementCount;

            //Cheking for wrap arround

            if (posn > MaxNum) {
                posn -= (MaxNum + 1);
                //i.e go back to position 1
            }

        }

    //dequeue F.I.F.O system
        ElementType Dequeue(void) {
            assert(ElementCount > 0);

            ElementType ReturnValue = Data[pos1++];
            --ElementCount;

            //checking for wrap arround

            if (pos1 > MaxNum) {
                pos1 -= (MaxNum + 1);
            }

            return ReturnValue;

        }

        int GetNumberOfElements(void) {
            return ElementCount;
        }

};


int main() {
    Queue<int> myQueue(70);

    //Add Elements to the queue
    myQueue.Enqueue(10);
    myQueue.Enqueue(20);
    myQueue.Enqueue(30);

    //Remove current first Element from Queue
    std::cout<<myQueue.Dequeue()<<"\n";

    //Check the number of elements in the Queue
    std::cout<<myQueue.GetNumberOfElements()<<"\n";


}