class Spreadsheet {
public:

    unordered_map<string, int> sheet;

    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {

        sheet[cell] = value;
        
    }
    
    void resetCell(string cell) {

        sheet[cell] = 0;
        
    }
    
    int getValue(string formula) {


        // extracting

        string xx = "";
        string yy = "";

        int i = 1;

        for(; i<formula.size(); i++){
            if(formula[i] != '+'){
                xx += formula[i];
            }else {
                break;
            }
        }

        i++;

        for( ; i<formula.size(); i++){
            yy += formula[i];
        }


        // refine 

        int x = 0 ;
        int y = 0 ;

        // A12
        if(xx[0] >= 'A' && xx[0] <= 'Z' ){

            if(sheet.find(xx) !=  sheet.end()){
                x = sheet[xx];
            }
            
            
        }else{

            x = stoi(xx);

        }
        
        // B23
        if(yy[0] >= 'A' && yy[0] <= 'Z' ){

            if(sheet.find(yy) !=  sheet.end()){
                y = sheet[yy];
            }

        }else{

            y = stoi(yy);

        }

        //



        

        return x + y;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */