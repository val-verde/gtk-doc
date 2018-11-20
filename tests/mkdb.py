# -*- python -*-
#
# gtk-doc - GTK DocBook documentation generator.
# Copyright (C) 2018  Stefan Sauer
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
#

import unittest

from gtkdoc import mkdb


class ScanSourceContent(unittest.TestCase):

    def setUp(self):
        mkdb.MODULE = 'test'

    def test_EmptyInput(self):
        mkdb.ScanSourceContent([])
        self.assertEqual({}, mkdb.SourceSymbolDocs)

    def test_FindsDocComment(self):
        mkdb.ScanSourceContent("""\
            /**
             * symbol:
             *
             * Description.
             */""".splitlines(keepends=True))
        self.assertEqual({'symbol': 'Description.\n'}, mkdb.SourceSymbolDocs)


if __name__ == '__main__':
    unittest.main()
