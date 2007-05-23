# $Id$

# -----------------------------------------------------------------------
# The script for environment setting for the Virtual Geometry Model example
# Copyright (C) 2007, Ivana Hrivnacova               
# All rights reserved. 
#           
# For the licensing terms see vgm/LICENSE.
# Contact: ivana@ipno.in2p3.fr
# -----------------------------------------------------------------------

# The environment setting for the E01 example 
#
# by I. Hrivnacova, IPN Orsay

export G4WORKDIR=`pwd`/N03
export PATH=${G4WORKDIR}/bin/${G4SYSTEM}:${PATH}
export LD_LIBRARY_PATH=${G4WORKDIR}/tmp/${G4SYSTEM}/exampleN03:${LD_LIBRARY_PATH}