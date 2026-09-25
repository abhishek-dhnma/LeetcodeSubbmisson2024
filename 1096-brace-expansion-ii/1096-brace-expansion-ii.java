class Solution {

    int i = 0;

    public List<String> solve(String expr){

        Set<String> rst = new HashSet<>();

        List<String> currGrp = new ArrayList<>();
        currGrp.add("");

        while(i < expr.length()){

            char c = expr.charAt(i);

            if(c == '{'){

                i++;
                List<String> innerword = solve(expr);

                List<String> newlist = new ArrayList<>();
                
                for(String str1 : currGrp){
                    
                    for(String str2 : innerword){

                       newlist.add(str1 + str2);

                    }


                }

                currGrp = newlist;

            }

            else if(c == ','){
                i++;
                rst.addAll(currGrp);
                currGrp = new ArrayList<>();
                currGrp.add("");

            }

            else if (c == '}'){
                i++;
                break;

            }

            else{
                i++;
                List<String> newlist = new ArrayList<>();
                for (String str : currGrp) {
                    newlist.add(str + c);
                }
                currGrp = newlist;

            }
        }

        rst.addAll(currGrp);

        List<String> finalans = new ArrayList<>(rst);
        Collections.sort(finalans);

        return finalans;

    }


    public List<String> braceExpansionII(String expression) {

        return solve(expression);
        
    }
}