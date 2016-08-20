# You are given two jugs with capacities x and y litres.
# There is an infinite amount of water supply available.
# You need to determine whether it is possible to measure exactly z litres using these two jugs.
# If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.
#
# Operations allowed:
#
# Fill any of the jugs completely with water.
# Empty any of the jugs.
# Pour water from one jug into another till the other jug is completely full or the first jug itself is empty

class Solution(object):
    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """
        def GCD(x, y):
            while x:
                x, y = y % x, x
            return y
        
        return z == x + y or (z < x + y and z % GCD(x, y) == 0)
