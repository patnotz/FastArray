#!/bin/sh

VS=$1
shift
HEADER_PATH=$1
shift
VH="$HEADER_PATH/fa_autoversion.hpp"

VERSION=$($VS)

if test -r $VH 
then
	PREVIOUS_VERSION=$(grep FA_VERSION $VH | sed -e 's/^#define FA_VERSION //' | sed -e 's/"//g')
else
	PREVIOUS_VERSION=unset
fi

if test "$VERSION" != "$PREVIOUS_VERSION"
then
	echo "#ifndef FA_AUTOVERSION_HPP_" > $VH
	echo "#define FA_AUTOVERSION_HPP_" >> $VH
	echo "" >> $VH
	echo "#define FA_VERSION \"$VERSION\"" >> $VH
	echo "#endif // FA_AUTOVERSION_HPP_" >> $VH
fi
