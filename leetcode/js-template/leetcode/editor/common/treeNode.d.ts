export declare class TreeNode {
    val: number;
    left: TreeNode | null;
    right: TreeNode | null;
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null);
    static createRoot(arr: (number | null)[]): TreeNode | null;
}
