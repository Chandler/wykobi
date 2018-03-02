/*
(***********************************************************************)
(*                                                                     *)
(* Wykobi Computational Geometry Library                               *)
(* Release Version 0.0.5                                               *)
(* http://www.wykobi.com                                               *)
(* Copyright (c) 2005-2017 Arash Partow, All Rights Reserved.          *)
(*                                                                     *)
(* The Wykobi computational geometry library and its components are    *)
(* supplied under the terms of the General Wykobi License agreement.   *)
(* The contents of the Wykobi computational geometry library and its   *)
(* components may not be copied or disclosed except in accordance with *)
(* the terms of that agreement.                                        *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
*/


#include <iostream>
#include <vector>

#include "wykobi.hpp"
#include "wykobi_utilities.hpp"
#include <emscripten/emscripten.h>

#ifdef __cplusplus
extern "C" {
#endif

void EMSCRIPTEN_KEEPALIVE segmentIntersect(double x1, double y1, double x2, double y2) {
   typedef double T;

   wykobi::segment<T,2> segment = wykobi::make_segment(x1,x2, y1, y2);
   wykobi::circle <T>   circle  = wykobi::make_circle(150.0,200.0,123.456);

   std::vector<wykobi::point2d<T> > intersection_points;

   wykobi::intersection_point
           (segment, circle, std::back_inserter(intersection_points));

   if (!intersection_points.empty()) {
      std::cout << "Segment intersects Circle at: ";

      for (auto p : intersection_points)
      {
         std::cout << p << "\n";
      }
   }
}

#ifdef __cplusplus
}
#endif