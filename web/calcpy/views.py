## @file calcpy/views.py
#  @brief calculation library interface to client

"""
calc library interface to client

export calculation results to client
"""
import calc

def getNumber(params):
    """the calculation from C++ library"""
    return {
        "number" : calc.getNumber()
    }
