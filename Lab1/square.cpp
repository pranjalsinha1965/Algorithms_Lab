
#include <cpp>

int main(){
    let squares;
    $$(
    $(l) {l+=1;},
    $(l) { l += (len(l) + 1) * (len(l) + 1); },
    $(l) { return len(l) <= 12; },
    squares);

    print("first 12 squares", squares);
}