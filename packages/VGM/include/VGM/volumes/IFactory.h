// $Id$
/// \ingroup VGM_volumes
//
/// \class VGM::IFactory
///
/// The VGM interface to geometry factory providing
/// functions for geometry construction and conversions.
///
/// Author: Ivana Hrivnacova; IPN Orsay

#ifndef VGM_I_FACTORY_H
#define VGM_I_FACTORY_H

#include <string>
#include <vector>

#include "VGM/common/Axis.h"
#include "VGM/common/Transform.h"

namespace VGM {

  class ISolid;
  class IVolume;
  class IPlacement;
  class IMaterialFactory;

  typedef std::vector<ISolid*>   SolidStore;
  typedef std::vector<IVolume*>  VolumeStore;

  class IFactory
  {
    public:
      virtual ~IFactory() {}
    
      //
      // solids
      //
      
                       /// Create the box solid
		       /// \param hx half-length along the x axis in mm
		       /// \param hy half-length along the y axis in mm
		       /// \param hz half-length along the z axis in mm
                       ///
      virtual ISolid*  CreateBox(const std::string& name, 
                               double hx, double hy, double hz) = 0;

                       /// Create the cons solid = phi segment of a conical tube
		       /// \param rin1 inside radius at -hz in mm
		       /// \param rin2 inside radius at +hz in mm
		       /// \param rout1 outside radius at -hz in mm
		       /// \param rout2 outside radius at +hz in mm
		       /// \param hz half-length along the z axis in mm
		       /// \param sphi starting angle of the segment in deg
		       /// \param dphi opening angle of the segment in deg
                       ///
      virtual ISolid*  CreateCons(const std::string& name, 
                               double rin1, double rout1, 
			       double rin2, double rout2, double hz,
	                       double sphi, double dphi) = 0; 

                       /// Create the elliptical tube solid
                       /// \param dx the semi-axis of the ellipse along x in mm
                       /// \param dx the semi-axis of the ellipse along y in mm
                       /// \param hz half-length along the z axis in mm
                       ///
      virtual ISolid*  CreateEllipticalTube(const std::string& name, 
                               double dx, double dy, double hz) = 0; 

                       /// Create the para solid = parallelepiped
		       /// \param hx half-length along the x axis in mm
		       /// \param hy half-length along the y axis in mm
		       /// \param hz half-length along the z axis in mm
		       /// \param alpha angle formed by the y axis and by the plane
		       ///        joining the centre of the faces parallel to the
		       ///        z-x plane at -hy and +hy in deg
		       /// \param theta polar angle of the line joining the centres
		       ///        of the faces at -hz and +hz in deg
		       /// \param phi azimuthal angle of the line joining the centres
 		       ///        of the faces at -hz and +hz in deg
                       ///
     virtual ISolid*  CreatePara(const std::string& name, 
                               double hx, double hy, double hz,
	                       double alpha, double theta, double phi) = 0;

                       /// Create the polycone solid = phi segment of a polycone
		       /// \param sphi starting angle of the segment in deg
		       /// \param dphi opening angle of the segment in deg
		       /// \param nofZplanes number of planes perpendicular to the
		       ///        z axis (has to be >= 2)
		       /// \param z  array of z positions of the planes in mm
		       /// \param rin array of inside radius of the planes in mm
		       /// \param rout array of outside radius of the planes in mm
                       ///
      virtual ISolid*  CreatePolycone(const std::string& name, 
                               double sphi, double dphi, int nofZplanes,
                               double* z, double* rin, double* rout) = 0;

                       /// Create the polyhedra solid = phi segment of a polyhedra
		       /// (polygone)
		       /// \param sphi starting angle of the segment in deg
		       /// \param dphi opening angle of the segment in deg
		       /// \param nofSides number of sides of the cross section
		       ///        between the given phi limits
		       /// \param nofZplanes number of planes perpendicular to the
		       ///        z axis (has to be >= 2)
		       /// \param z  array of z positions of the planes in mm
		       /// \param rin array of inside radius of the planes in mm
		       /// \param rout array of outside radius of the planes in mm
                       ///
      virtual ISolid*  CreatePolyhedra(const std::string& name, 
                               double sphi, double dphi, 
			       int nofSides, int nofZplanes,
                               double* z, double* rin, double* rout) = 0;

                       /// Create the sphere solid = phi segment of a spherical
		       /// shell
		       /// \param rin inside radius of the shell in mm
		       /// \param rout outside radius of the shell in mm
		       /// \param sphi starting azimuthal angle of the segment in deg
		       /// \param dphi opening azimuthal angle of the segment in deg
		       /// \param stheta starting polar angle of the segment in deg
		       /// \param dtheta opening polar angle of the segment in deg
                       ///
      virtual ISolid*  CreateSphere(const std::string& name, 
                               double rin, double rout, 
			       double sphi, double dphi, 
	                       double stheta, double dtheta) = 0;

                       /// Create the torus solid = phi segment of a torus
		       /// \param rin inside radius of the torus in mm
		       /// \param rout outside radius of the torus in mm
		       /// \param rax axial (swept) radius of the torus in mm
		       /// \param sphi starting angle of the segment in deg
		       ///        (with 0 being the +x axis)
		       /// \param dphi opening angle of the segment in deg
                       ///
      virtual ISolid*  CreateTorus(const std::string& name, 
                               double rin, double rout, double rax, 
			       double sphi, double dphi) = 0;

                       /// Create the trap solid = general trapezoid
                       /// ( Note that of the 11 parameters described below, only 9 
		       ///   are really independent)
		       /// \param hz half-length along the z axis in mm
		       /// \param theta polar angle of the line joining the centres
		       ///        of the faces at -hz and +hz in deg
		       /// \param phi azimuthal angle of the line joining the centres
 		       ///        of the faces at -hz and +hz in deg
		       /// \param dy1 half-length along y of the face at -hz in mm
                       /// \param dx1 half-length along x of the side at -hy 
		       ///        of the face at -hz in mm
                       /// \param dx2 half-length along x of the side at +hy
		       ///        of the face at +hz in mm
                       /// \param alpha1  angle with respect to the y axis from the 
		       ///        centre of the side at -hy to the centre at +hy
		       ///        of the face at -hz
		       /// \param dy2 half-length along y of the face at +hz in mm
                       /// \param dx3 half-length along x of the side at -hy 
		       ///        of the face at +hz in mm
                       /// \param dx4 half-length along x of the side at +hy
		       ///        of the face at +hz in mm
                       /// \param alpha1  angle with respect to the y axis from the 
		       ///        centre of the side at -hy to the centre at +hy
		       ///        of the face at +hz
                       ///
      virtual ISolid*  CreateTrap(const std::string& name, 
                               double hz, double theta, double phi,
                               double dy1, double dx1, double dx2, 
			       double alpha1, 
                               double dy2, double dx3, double dx4, 
			       double alpha2) = 0;

                       /// Create the trd solid = a trapezoid with the x and y dimensions 
		       /// varying along z 
                       /// \param hx1 half-length along x at the surface positioned 
		       ///            at -hz in mm
                       /// \param hx2 half-length along x at the surface positioned 
		       ///            at +hz in mm
                       /// \param hy1 half-length along y at the surface positioned 
		       ///            at -hz in mm
                       /// \param hy2 half-length along y at the surface positioned 
		       ///            at +hz in mm
		       /// \param hz half-length along the z axis in mm
                       ///
      virtual ISolid*  CreateTrd(const std::string& name, 
                               double hx1, double hx2, double hy1, double hy2, 
			       double hz) = 0;

                       /// Create the tubs solid = phi segment of a tube
		       /// \param rin inside radius in mm
		       /// \param rout outside radius in mm
		       /// \param hz half-length along the z axis in mm
		       /// \param sphi starting angle of the segment in deg
		       /// \param dphi opening angle of the segment in deg
		       ///
      virtual ISolid*  CreateTubs(const std::string& name, 
                               double rin, double rout, double hz, 
			       double sphi, double dphi) = 0;

      //
      // Boolean solids			       
      // 

                       /// Create the intersection of two solids
		       /// \param solidA, solidB constituent solids
		       /// \param transform 3D displacement of the solidB 
		       ///        with respect to solid A
      virtual ISolid*  CreateIntersectionSolid(const std::string& name, 
                               VGM::ISolid* solidA, VGM::ISolid* solidB, 
                               const VGM::Transform& transform) = 0;
 
                       /// Create the subtraction of two solids
		       /// \param solidA, solidB constituent solids
		       /// \param transform 3D displacement of the solidB 
		       ///        with respect to solid A
      virtual ISolid*  CreateSubtractionSolid(const std::string& name, 
                               VGM::ISolid* solidA, VGM::ISolid* solidB, 
                               const VGM::Transform& transform) = 0;

                       /// Create the union of two solids
		       /// \param solidA, solidB constituent solids
		       /// \param transform 3D displacement of the solidB 
		       ///        with respect to solid A
      virtual ISolid*  CreateUnionSolid(const std::string& name, 
                               VGM::ISolid* solidA, VGM::ISolid* solidB, 
                               const VGM::Transform& transform) = 0;


      //
      // volumes
      //
      
                          /// Create the volume
		          /// \param solid the associated solid
		          /// \param mediumName the name of the associated medium
		          ///
      virtual IVolume*    CreateVolume(
                                 const std::string& name, 
                                 VGM::ISolid* solid, 
                                 const std::string& mediumName) = 0;

      //
      // placements
      //
      
                          /// Create the simple volume placement
		          /// \param copyNo the copy number of this placement
		          /// \param volume the associated volume
		          /// \param motherVolume the associated mother volume
		          /// \param transform 3D transformation
		          ///
      virtual IPlacement* CreatePlacement(
                               const std::string& name, 
                               int copyNo,
                               VGM::IVolume* volume, 
			       VGM::IVolume* motherVolume,
			       const VGM::Transform& transform) = 0;

                          /// Create the multiple volume placement
		          /// \param volume the associated volume which will be replicated
		          /// \param motherVolume the associated mother volume
		          /// \param axis the replication axis
		          /// \param nofItems number of replications
		          /// \param with the replication width (the unit depends on the axis;
		          ///        can be mm or deg)
		          ///  \param offset the replication offset (the unit depends on the axis;
		          ///        can be mm or deg)
		          /// 
      virtual IPlacement* CreateMultiplePlacement(
                               const std::string& name, 
                               VGM::IVolume* volume, 
			       VGM::IVolume* motherVolume,
			       VGM::Axis axis,
                               int nofItems,
                               double  width,
                               double  offset) = 0;
			       
            // TO DO: IVolume* volume parameter is redundant;
	    // IVolume and ISolid should be created automatically
	    // via factory; this is however not available in
	    // Geant4 now (it would have to be done on the VGM level)
	    // - should be possible with G4Division class, so lets wait
	    // for it 	     			       			       
			       
      ///
      // top volume
      //
 		          ///
                          /// Return the top volume placement
      virtual IPlacement* Top() const = 0;		       
			       
      //
      // access
      //
	                  ///
                          /// Return the name of this factory
      virtual std::string Name() const = 0;

	                          ///
                                  /// Return the store of solids
      virtual const SolidStore&   Solids() const = 0;			       
	                          ///
                                  /// Return the store of volumes
      virtual const VolumeStore&  Volumes() const = 0;	
	                          ///
                                  /// Return the associated material factory
      virtual IMaterialFactory*   MaterialFactory() const = 0;

      //
      // listings
      //
	            ///
                    /// Print all solids
      virtual void  PrintSolids() const = 0;			       
	            ///
                    /// Print all volumes
      virtual void  PrintVolumes() const = 0;	

      //
      // export
      //
	           ///
                   /// Export geometry to the specified factory
      virtual bool Export(IFactory* factory) const = 0;			       

      //
      // debug
      //
	           ///
                   /// Set the debug level
      virtual void SetDebug (int debug) = 0;			       
	           ///
                   /// Return the debug level
      virtual int  Debug() const = 0;

    private:
  
      //
      // import
      //
                   /// Import native geometry                                   \n
	           /// (As the general factory cannot handle the propre top volume
		   /// type of the native geometry model, this has to be casted to void*.
		   /// That's why this function is declared in the private area
		   /// and leaves the possibility to implement the geometry model 
		   /// specific Import() function by the concrete factory in the public
		   /// area.)   
		   /// 
      virtual bool Import(void* /*topVolume*/) = 0;
  };
  
}  

#endif //VGM_I_FACTORY_H