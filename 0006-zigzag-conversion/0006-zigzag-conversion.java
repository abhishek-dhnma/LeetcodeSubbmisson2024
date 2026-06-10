class Solution {
    public String convert(String s, int nr) {

        if(nr == 1 || nr >= s.length()){
            return s;
        }

        StringBuilder[] rb = new StringBuilder[nr];

        for(int i=0;i <nr; i++){
            rb[i] = new StringBuilder();
        }

        int cr = 0;
        boolean md = true;

        for(char cc : s.toCharArray()){
            rb[cr].append(cc);

            if(cr == 0){
                md = true;
            }else if(cr == nr -1){
                md = false;
            }

            cr += md ? 1 : -1;
        }

        StringBuilder fr = new StringBuilder();
        for(StringBuilder ra : rb){
            fr.append(ra);
        }

        return fr.toString();
        
    }
}