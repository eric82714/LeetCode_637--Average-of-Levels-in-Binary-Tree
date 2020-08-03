# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        nodes = [root]
        result = []
        
        while True:
            row_sum, row_count = 0, 0
            new_nodes = []
            
            for node in nodes:
                if not node: continue
                row_sum += node.val
                row_count += 1
                new_nodes.append(node.left)
                new_nodes.append(node.right)
                
            if row_count == 0: break
            result.append(row_sum / float(row_count))
            nodes = new_nodes
        
        return result
