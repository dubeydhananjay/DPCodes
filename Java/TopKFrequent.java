class TopKFrequent {
    public static int[] topKFrequentM(int[] nums, int k) {
        HashMap<Integer,Integer> hm = new HashMap<Integer,Integer>();
        int size = nums.length;
        int[] res = new int[k];
        for(int i = 0; i < size; i++) {
            if(hm.get(nums[i]) == null) {
                hm.put(nums[i], 1);
            }
            else {
                hm.put(nums[i], hm.get(nums[i]) + 1);
            }
        }
        PriorityQueue<Pair<Integer, Integer>> pq =  new PriorityQueue<>((a, b) -> a.getValue() - b.getValue());
        for (Map.Entry<Integer,Integer> map : hm.entrySet()) {
            pq.add(new Pair<>(map.getKey(), map.getValue()));
            if(pq.size() > k) {
                pq.poll();
            }
        }
        for(int i = 0; i < k; i++) {
            res[i] = pq.peek().getKey();
            pq.poll();
        }
        return res;
        
    }

    public static void main(String[] args) {
        int[] nums = {1,1,1,2,2,3};
        int k = 2;
        System.out.println(topKFrequentM(nums, k));
    }
}