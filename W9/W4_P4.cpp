#include <iostream>
#include<vector>
using namespace std;

struct compare{
    bool operator()(const int&e1,const int&e2)const {
        //e1이 계속 바뀌는 값들
        //e2이 우선순위 높은 minVal
        if(e1%2!=0){
            //e1 홀수
            if(e2%2==0){
                //e2 짝수
                return false;
            }
            else{
                //e2 홀수
                //e1이 작으면 바꿔야지
                return e1<e2;
            }
        }
        else{
            //e1이 짝수
            if(e2%2==0){
                //e2 짝수
                //비교해서 e1이 작으면 바꿔야지
                return e1<e2;
            }
            else{
                //e2 홀수
                return true;
            }
        }
        return e1<e2;
    }
};

class unsortedSeqPQ{
private:
    vector<int> seq;

public:
    int size(){
        return seq.size();
    }
    bool empty(){
        return seq.size()==0;
    }
    void insert(int e){
        seq.push_back(e);
    }
    int min(){
        if(empty()){
            return -1;
        }

        compare C;
        int minVal=seq[0];

        for(int i=0; i<seq.size(); i++){
            if(C(seq[i],minVal)){
                minVal=seq[i];
            }
        }

        return minVal;


    }
    void removeMin(){
        if(empty()){
            return;
        }

        compare C;
        int minIdx=0;
        for(int i=0; i<seq.size(); i++){
            if(C(seq[i],seq[minIdx])){
                minIdx=i;
            }
        }
        seq.erase(seq.begin()+minIdx);
    }

    void print(){
        for(int i=0; i<seq.size(); i++){
            cout<<seq[i]<<" ";
        }

        cout<<endl;
    }
};

int main(){
    int T,N,data;

    cin>>T;

    for(int i=0; i<T; i++){

        unsortedSeqPQ *pq=new unsortedSeqPQ();
        cin>>N;
        for(int i=0; i<N; i++){
            cin>>data;
            pq->insert(data);
        }

        for(int i=0; i<N; i++){
            cout<<pq->min()<<" ";
            pq->removeMin();

        }
        cout<<endl;



        delete pq;
    }
}