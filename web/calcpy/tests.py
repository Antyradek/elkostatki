## @file calcpy/tests.py
#  @brief c++ calculation library Python API unit testing

import django.test
import calc
import views

class CalcPyLibraryTestCase(django.test.TestCase):
    """integration test, call C++ library interface from Python"""

    def test01getNumber(self):
        """test the return number"""
        self.assertEqual( calc.getNumber(), 1234 )

class CalcPyViewTestCase(django.test.TestCase):
    """module view test"""

    def test01getNumber(self):
        """check if service return proper dict"""
        self.assertEqual( views.getNumber({}), {'number': 1234})




