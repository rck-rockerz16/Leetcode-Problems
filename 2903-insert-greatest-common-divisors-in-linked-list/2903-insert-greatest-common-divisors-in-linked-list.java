/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    private int greatestCommonDivisors(int num1, int num2) {

        int result = Math.min(num1, num2);
        while (result != 0) {
            if (num1 % result == 0 && num2 % result == 0)
                break;
            --result;
        }
        return result;
    }

    public ListNode insertGreatestCommonDivisors(ListNode head) {
        ListNode curr = head, nextNode = head.next;

        if (nextNode == null)
            return head;

        if (nextNode.next == null) {
            ListNode newNode = new ListNode(greatestCommonDivisors(curr.val, nextNode.val));
            newNode.next = nextNode;
            curr.next = newNode;
        }

        while (nextNode != null) {
            int gcd = greatestCommonDivisors(curr.val, nextNode.val);
            ListNode newNode = new ListNode(gcd);
            newNode.next = nextNode;
            curr.next = newNode;
            curr = nextNode;
            nextNode = nextNode.next;
        }
        return head;
    }
}