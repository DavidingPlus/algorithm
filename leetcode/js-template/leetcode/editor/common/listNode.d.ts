export declare class ListNode {
    val: number;
    next: ListNode | null;
    constructor(val?: number, next?: ListNode | null);
    static print(head: ListNode | null): void;
    static createHead(nums: number[]): ListNode | null;
}
