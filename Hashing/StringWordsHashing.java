
import java.util.StringTokenizer;
import java.util.HashMap;
import java.util.Iterator;

/**
 *
 * @author rafiul islam
 */
public class StringWordsHashing {
    private static final String data = "Tata Tata woooohoo tata Tata Teta tata i am Going";
    public static void main(String[] args) {
        
        StringTokenizer st = new StringTokenizer(data, " ");
        HashMap<String, Integer> hmp = new HashMap<>();
        while(st.hasMoreElements()){
            String element = (String) st.nextElement();
            if(!element.startsWith("T")) continue;
            if(hmp.get(element) == null){
                hmp.put(element, 1);
            }
            else{
                hmp.put(element, hmp.get(element)+1);
            }
        }
        Iterator it = hmp.entrySet().iterator();
        while(it.hasNext()){
            HashMap.Entry pair = (HashMap.Entry<String,Integer>)it.next();         
            System.out.println(pair.getKey()+": "+pair.getValue());
        }
    }
}
