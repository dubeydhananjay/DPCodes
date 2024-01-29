class TopKClosestElement {
    public static List<Integer> findClosestElements(int[] arr, int k, int x) {
        Queue<Integer> pq = new PriorityQueue<>((a,b)->(Math.abs(a-x) < Math.abs(b-x)) ? 1 : -1);
        List<Integer> list = new ArrayList<Integer> (); 
        int size = arr.length;
        for(int i = 0; i < size; i++) {
            pq.add(arr[i]);
            if(pq.size() > k) {
                pq.poll();
            }
        }
        size = pq.size();
        for(int i = 0; i < size; i++) {
            list.add(pq.peek());
            pq.poll();
        }
        Collections.sort(list);
        return list;
    }

    public static void main(String[] args) {
        int[] nums = {1,2,3,4,5};
        int k = 2;
        int x = 3;
        System.out.println(findClosestElements(nums, k, x));
    }
}