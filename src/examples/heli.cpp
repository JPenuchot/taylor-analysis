#include <iostream>
#include <tuple>

#include <transform.hpp>
#include <interval.hpp>

#include "heli.hpp"

void heli()
{
  using namespace std;

  //  Tuple indexes for better readability
  constexpr std::size_t x1  = 0  , x2  = 1  , x3  = 2  , x4  = 3
                      , x5  = 4  , x6  = 5  , x7  = 6  , x8  = 7
                      , x9  = 8  , x10 = 9  , x11 = 10 , x12 = 11
                      , x13 = 12 , x14 = 13 , x15 = 14 , x16 = 15
                      , x17 = 16 , x18 = 17 , x19 = 18 , x20 = 19
                      , x21 = 20 , x22 = 21 , x23 = 22 , x24 = 23
                      , x25 = 24 , x26 = 25 , x27 = 26 , x28 = 27
                      , t   = 28
                      ;

  //  Initial state
  auto init_state = make_tuple
    ( make_interval(0. , 0.1) /* x1   */ , make_interval(0. , 0.1) /* x2   */
    , make_interval(0. , 0.1) /* x3   */ , make_interval(0. , 0.1) /* x4   */
    , make_interval(0. , 0.1) /* x5   */ , make_interval(0. , 0.1) /* x6   */
    , make_interval(0. , 0.1) /* x7   */ , make_interval(0. , 0.1) /* x8   */
    , make_interval(0. , 0. ) /* x9   */ , make_interval(0. , 0. ) /* x10  */
    , make_interval(0. , 0. ) /* x11  */ , make_interval(0. , 0. ) /* x12  */
    , make_interval(0. , 0. ) /* x13  */ , make_interval(0. , 0. ) /* x14  */
    , make_interval(0. , 0. ) /* x15  */ , make_interval(0. , 0. ) /* x16  */
    , make_interval(0. , 0. ) /* x17  */ , make_interval(0. , 0. ) /* x18  */
    , make_interval(0. , 0. ) /* x19  */ , make_interval(0. , 0. ) /* x20  */
    , make_interval(0. , 0. ) /* x21  */ , make_interval(0. , 0. ) /* x22  */
    , make_interval(0. , 0. ) /* x23  */ , make_interval(0. , 0. ) /* x24  */
    , make_interval(0. , 0. ) /* x25  */ , make_interval(0. , 0. ) /* x26  */
    , make_interval(0. , 0. ) /* x27  */ , make_interval(0. , 0. ) /* x28  */
    , make_interval(0. , 0. ) /* t    */
    );

  constexpr double dt = 0.01;

  //  Polymorphic lambda : fully type agnostic
  auto trans = make_tuple
    //  x1
    ( [&](const auto& states){ return get<x1>(states)  + dt * ( 0.998573780060   * get<x4>(states) + 0.053384274244  * get<x5>(states)); }
    //  x2
    , [&](const auto& states){ return get<x2>(states)  + dt * ( 1.000000000000   * get<x3>(states) - 0.003182219341  * get<x4>(states) + 0.059524655342   * get<x5>(states)); }
    //  x3
    , [&](const auto& states){ return get<x3>(states)  + dt * (-11.570495605469  * get<x3>(states) - 2.544637680054  * get<x4>(states) - 0.063602626324   * get<x5>(states) + 0.106780529022   * get<x6>(states)  - 0.094918668270  * get<x7>(states)  + 0.007107574493 * get<x8>(states)  - 3.700790207851 * get<x9>(states)  - 16.213284674534 * get<x10>(states) - 2.984968535139  * get<x11>(states) - 0.493137919288  * get<x12>(states) - 1.186954196152  * get<x13>(states) - 0.031106608756  * get<x14>(states) + 0.024595252653 * get<x15>(states) + 0.008231369923 * get<x16>(states) + 0.231787619674 * get<x17>(states) + 0.745302732591 * get<x18>(states) + 7.895709940231 * get<x19>(states) + 2.026930360369 * get<x20>(states) + 0.271792657736 * get<x21>(states) + 0.315196108541 * get<x22>(states) + 0.015876847710 * get<x23>(states) + 0.009288507454 * get<x24>(states) + 0.087920280806 * get<x25>(states) - 0.103727794204 * get<x26>(states) - 4.447282126346 * get<x27>(states) + 0.016271459306 * get<x28>(states)); }
    //  x4
    , [&](const auto& states){ return get<x4>(states)  + dt * ( 0.439356565475   * get<x3>(states) - 1.998182296753  * get<x4>(states) + 0.016651883721   * get<x6>(states) + 0.018462046981   * get<x7>(states)  - 0.001187470742  * get<x8>(states)  - 7.517319654181 * get<x9>(states)  + 0.236494174025 * get<x10>(states) - 0.028725044803  * get<x11>(states) - 2.442989538035  * get<x12>(states) + 0.034510550810  * get<x13>(states) - 0.004683216652  * get<x14>(states) - 0.005154038690  * get<x15>(states) - 0.002104275246 * get<x16>(states) - 0.079935853309 * get<x17>(states) + 1.420125114638 * get<x18>(states) - 0.117856066698 * get<x19>(states) - 0.226142434271 * get<x20>(states) - 0.002585832387 * get<x21>(states) - 0.001365917341 * get<x22>(states) + 0.035962654791 * get<x23>(states) + 0.028993699893 * get<x24>(states) - 0.045896888864 * get<x25>(states) + 0.716358354284 * get<x26>(states) + 0.029085601036 * get<x27>(states) - 0.001242728387 * get<x28>(states)); }
    //  x5
    , [&](const auto& states){ return get<x5>(states)  + dt * (-2.040895462036   * get<x3>(states) - 0.458999156952  * get<x4>(states) - 0.735027790070   * get<x5>(states) + 0.019255757332   * get<x6>(states)  - 0.004595622420  * get<x7>(states)  + 0.002120360732 * get<x8>(states)  - 0.740775522612 * get<x9>(states)  - 2.555714688932  * get<x10>(states) - 0.339301128908  * get<x11>(states) - 0.033104023297  * get<x12>(states) - 1.446467788369  * get<x13>(states) - 0.007442776396  * get<x14>(states) - 0.000012314482 * get<x15>(states) + 0.030657946816 * get<x16>(states) + 1.002118140789 * get<x17>(states) + 0.153644862643 * get<x18>(states) + 1.273828227991  * get<x19>(states) + 1.983204935524 * get<x20>(states) + 0.048757213739 * get<x21>(states) + 0.060295617991 * get<x22>(states) + 0.001605314985 * get<x23>(states) + 0.000554368427 * get<x24>(states) + 0.475422075598 * get<x25>(states) - 0.010880647601 * get<x26>(states) - 0.775712358056 * get<x27>(states) - 0.408545111762 * get<x28>(states)); }
    //  x6
    , [&](const auto& states){ return get<x6>(states)  + dt * (-32.103607177734  * get<x1>(states) - 0.503355026245  * get<x3>(states) + 2.297859191895   * get<x4>(states) - 0.021215811372   * get<x6>(states)  - 0.021167919040  * get<x7>(states)  + 0.015811592340 * get<x8>(states)  + 8.689411857722 * get<x9>(states)  - 0.215429806172  * get<x10>(states) + 0.063500560122  * get<x11>(states) + 2.847523923644  * get<x12>(states) - 0.297021616015  * get<x13>(states) + 0.001323463163  * get<x14>(states) + 0.002124820781 * get<x15>(states) + 0.068860932948 * get<x16>(states) + 1.694077894544 * get<x17>(states) - 1.639571645676 * get<x18>(states) + 0.110652545728 * get<x19>(states) + 0.728735301618 * get<x20>(states) + 0.003107735169 * get<x21>(states) + 0.003335187976 * get<x22>(states) - 0.042347579477 * get<x23>(states) - 0.034247794709 * get<x24>(states) + 0.469091132962 * get<x25>(states) - 0.814424502262 * get<x26>(states) - 0.018082452136 * get<x27>(states) + 0.016747349252 * get<x28>(states)); }
    //  x7
    , [&](const auto& states){ return get<x7>(states)  + dt * ( 0.102161169052   * get<x1>(states) + 32.057830810547 * get<x2>(states) - 2.347217559814   * get<x3>(states) - 0.503611564636   * get<x4>(states)  + 0.834947586060  * get<x5>(states)  + 0.021226570010 * get<x6>(states)  - 0.037879735231 * get<x7>(states)  + 0.000354003860  * get<x8>(states)  - 0.560681623936  * get<x9>(states)  - 3.574948145694  * get<x10>(states) - 0.788176766644  * get<x11>(states) - 0.107590635594  * get<x12>(states) + 0.908657075077 * get<x13>(states) - 0.008720966051 * get<x14>(states) + 0.005669792925 * get<x15>(states) + 0.044884407612 * get<x16>(states) + 0.788227489086 * get<x17>(states) + 0.111065913657 * get<x18>(states) + 1.709840089441 * get<x19>(states) - 0.946574755181 * get<x20>(states) + 0.054255711842 * get<x21>(states) + 0.060392345409 * get<x22>(states) + 0.003299051857 * get<x23>(states) + 0.001965592530 * get<x24>(states) - 0.035607238660 * get<x25>(states) - 0.021984114632 * get<x26>(states) - 0.893130060176 * get<x27>(states) + 0.503048977806 * get<x28>(states)); }
    //  x8
    , [&](const auto& states){ return get<x8>(states)  + dt * (-1.910972595215   * get<x1>(states) + 1.713829040527  * get<x2>(states) - 0.004005432129   * get<x3>(states) - 0.057411193848   * get<x4>(states)  + 0.013989634812  * get<x6>(states)  - 0.000906753354 * get<x7>(states)  - 0.290513515472 * get<x8>(states)  - 1.440209153996  * get<x9>(states)  - 1.089782421583  * get<x10>(states) - 0.599051729911  * get<x11>(states) - 0.930901394778  * get<x12>(states) + 5.044060722850  * get<x13>(states) + 0.079229241316 * get<x14>(states) + 0.074101747848 * get<x15>(states) - 1.301808243838 * get<x16>(states) - 31.393874531397 * get<x17>(states) + 0.233327947688 * get<x18>(states) + 0.478559456452 * get<x19>(states) - 9.198865975131 * get<x20>(states) - 0.002820980233 * get<x21>(states) - 0.034669033757 * get<x22>(states) + 0.022125233836 * get<x23>(states) + 0.019923408940 * get<x24>(states) - 8.159414332666 * get<x25>(states) - 0.129736796488 * get<x26>(states) - 0.298841506489 * get<x27>(states) - 0.300193732750 * get<x28>(states)); }
    //  x9
    , [&](const auto& states){ return get<x9>(states)  + dt * ( 0.050176870833   * get<x1>(states) - 0.003161246171  * get<x2>(states) - 0.486165175190   * get<x3>(states) + 0.266534777047   * get<x4>(states)  + 0.003826227932  * get<x5>(states)  + 0.000001339204 * get<x6>(states)  + 0.000001199431 * get<x7>(states)  - 0.000022435600  * get<x8>(states)  - 0.020657323970  * get<x9>(states)  + 0.001301453941  * get<x10>(states) + 0.213359280279  * get<x11>(states) + 0.881596311923  * get<x12>(states) + 0.051809053856 * get<x13>(states) - 0.000000551337 * get<x14>(states) - 0.000000493794 * get<x15>(states) + 0.000009236516 * get<x16>(states)); }
    //  x10
    , [&](const auto& states){ return get<x10>(states) + dt * (-0.019757788570   * get<x1>(states) + 0.009012833714  * get<x2>(states) + 0.311015942657   * get<x3>(states) + 2.810181204790   * get<x4>(states)  - 0.001602140073  * get<x5>(states)  - 0.000000613279 * get<x6>(states)  - 0.000000549271 * get<x7>(states)  + 0.000010274224  * get<x8>(states)  + 0.008134087133  * get<x9>(states)  - 0.003710494952  * get<x10>(states) + 0.863507011470  * get<x11>(states) - 1.236460821044  * get<x12>(states) + 0.060184240645 * get<x13>(states) + 0.000000252481 * get<x14>(states) + 0.000000226129 * get<x15>(states) - 0.000004229797 * get<x16>(states)); }
    //  x11
    , [&](const auto& states){ return get<x11>(states) + dt * (-0.030385323449   * get<x1>(states) + 0.003110159427  * get<x2>(states) + 0.312812882924   * get<x3>(states) + 0.287354391281   * get<x4>(states)  - 0.002331730630  * get<x5>(states)  - 0.000000824205 * get<x6>(states)  - 0.000000738183 * get<x7>(states)  + 0.000013807861  * get<x8>(states)  - 8.414922645141  * get<x9>(states)  - 36.922139523656 * get<x10>(states) - 18.505141519315 * get<x11>(states) - 3.793715804769  * get<x12>(states) - 2.765572372983 * get<x13>(states) + 0.035944961732 * get<x14>(states) - 0.038910104720 * get<x15>(states) + 0.025846348888 * get<x16>(states) + 0.527826299191 * get<x17>(states) + 1.697201876759 * get<x18>(states) + 17.980094722474 * get<x19>(states) + 4.615721721183 * get<x20>(states) + 0.618925691035 * get<x21>(states) + 0.717763941510 * get<x22>(states) + 0.036154725527 * get<x23>(states) + 0.021151770407 * get<x24>(states) + 0.200211885807 * get<x25>(states) - 0.236208723376 * get<x26>(states) - 10.127341872304 * get<x27>(states) + 0.037053334254 * get<x28>(states)); }
    //  x12
    , [&](const auto& states){ return get<x12>(states) + dt * ( 0.002667394037   * get<x1>(states) + 0.004496152836  * get<x2>(states) + 0.045956750452   * get<x3>(states) + 1.764514260408   * get<x4>(states)  + 0.000146052012  * get<x5>(states)  + 0.000000019584 * get<x6>(states)  + 0.000000017540 * get<x7>(states)  - 0.000000328097  * get<x8>(states)  - 17.119523267503 * get<x9>(states)  + 0.536693033369  * get<x10>(states) + 0.353775293385  * get<x11>(states) - 8.335731095093  * get<x12>(states) + 0.078527228401 * get<x13>(states) + 0.005987264162 * get<x14>(states) + 0.006725273267 * get<x15>(states) - 0.005979187005 * get<x16>(states) - 0.182029763642 * get<x17>(states) + 3.233906041666 * get<x18>(states) - 0.268381596955 * get<x19>(states) - 0.514971094398 * get<x20>(states) - 0.005888452287 * get<x21>(states) - 0.003110464210 * get<x22>(states) + 0.081894084826 * get<x23>(states) + 0.066024394813 * get<x24>(states) - 0.104516302587 * get<x25>(states) + 1.631289796960 * get<x26>(states) + 0.066233671911 * get<x27>(states) - 0.002829938571 * get<x28>(states)); }
    //  x13
    , [&](const auto& states){ return get<x13>(states) + dt * ( 0.024056576806   * get<x1>(states) - 0.001361685819  * get<x2>(states) - 0.230715295944   * get<x3>(states) + 0.185551143531   * get<x4>(states)  + 0.001832537128  * get<x5>(states)  + 0.000000640359 * get<x6>(states)  + 0.000000573525 * get<x7>(states)  - 0.000010727892  * get<x8>(states)  - 1.696796379292  * get<x9>(states)  - 5.819307733117  * get<x10>(states) - 2.712299197847  * get<x11>(states) - 0.615817527040  * get<x12>(states) - 4.029675752634 * get<x13>(states) + 0.002306818331 * get<x14>(states) - 0.004623901048 * get<x15>(states) + 0.071938991843 * get<x16>(states) + 2.282021405408 * get<x17>(states) + 0.349879770769 * get<x18>(states) + 2.900759066988 * get<x19>(states) + 4.516150272075 * get<x20>(states) + 0.111029828612 * get<x21>(states) + 0.137305059460 * get<x22>(states) + 0.003655620040 * get<x23>(states) + 0.001262406662 * get<x24>(states) + 1.082630189953 * get<x25>(states) - 0.024777388732 * get<x26>(states) - 1.766450614425 * get<x27>(states) - 0.930338103031 * get<x28>(states)); }
    //  x14
    , [&](const auto& states){ return get<x14>(states) + dt * (-1.753103616578   * get<x1>(states) + 0.521869609890  * get<x2>(states) + 23.319318958026  * get<x3>(states) + 145.082271971311 * get<x4>(states)  - 0.138741289403  * get<x5>(states)  - 0.000051341929 * get<x6>(states)  - 0.000045983385 * get<x7>(states)  + 0.000860128319  * get<x8>(states)  - 11.594360544437 * get<x9>(states)  - 0.705424902410  * get<x10>(states) - 10.592707880324 * get<x11>(states) - 54.888617486514 * get<x12>(states) - 0.619258600252 * get<x13>(states) - 0.018180886764 * get<x14>(states) - 0.016310350542 * get<x15>(states) + 0.172267463350 * get<x16>(states) + 3.857750758541 * get<x17>(states) - 3.733629238750 * get<x18>(states) + 0.251977753557 * get<x19>(states) + 1.659474556422 * get<x20>(states) + 0.007076928248 * get<x21>(states) + 0.007594883320 * get<x22>(states) - 0.096433822422 * get<x23>(states) - 0.077989008913 * get<x24>(states) + 1.068213380174 * get<x25>(states) - 1.854605830991 * get<x26>(states) - 0.041177323469 * get<x27>(states) + 0.038137029879 * get<x28>(states)); }
    //  x15
    , [&](const auto& states){ return get<x15>(states) + dt * ( 1.708539622488   * get<x1>(states) + 0.111898315003  * get<x2>(states) - 13.174473231922  * get<x3>(states) + 91.462755556230  * get<x4>(states)  + 0.127584976026  * get<x5>(states)  + 0.000043171229 * get<x6>(states)  + 0.000038665459 * get<x7>(states)  - 0.000723245056  * get<x8>(states)  - 1.878010842263  * get<x9>(states)  + 23.870898681235 * get<x10>(states) + 1.639719754761  * get<x11>(states) - 40.888303474223 * get<x12>(states) + 2.851614162302 * get<x13>(states) + 0.001349430570 * get<x14>(states) - 0.024984412428 * get<x15>(states) + 0.102862439056 * get<x16>(states) + 1.794950045519 * get<x17>(states) + 0.252919074168 * get<x18>(states) + 3.893644396914 * get<x19>(states) - 2.155538119928 * get<x20>(states) + 0.123550997381 * get<x21>(states) + 0.137525326941 * get<x22>(states) + 0.007512594224 * get<x23>(states) + 0.004476043338 * get<x24>(states) - 0.081084731931 * get<x25>(states) - 0.050062181420 * get<x26>(states) - 2.033833968448 * get<x27>(states) + 1.145542115841 * get<x28>(states)); }
    //  x16
    , [&](const auto& states){ return get<x16>(states) + dt * (-0.069753861204   * get<x1>(states) + 0.041269247265  * get<x2>(states) + 1.243498527057   * get<x3>(states) + 13.467483657041  * get<x4>(states)  - 0.005772466581  * get<x5>(states)  - 0.000002269708 * get<x6>(states)  - 0.000002032820 * get<x7>(states)  + 0.000038024292  * get<x8>(states)  - 5.161896992464  * get<x9>(states)  - 0.784811430978  * get<x10>(states) - 1.913888711445  * get<x11>(states) - 8.087612492321  * get<x12>(states) + 11.488701354150 * get<x13>(states) + 0.194411237470 * get<x14>(states) + 0.167838434014 * get<x15>(states) - 3.255004272242 * get<x16>(states) - 71.490067651024 * get<x17>(states) + 0.531333931032 * get<x18>(states) + 1.089774627294 * get<x19>(states) - 20.947639012098 * get<x20>(states) - 0.006423930487 * get<x21>(states) - 0.078948253623 * get<x22>(states) + 0.050383537787 * get<x23>(states) + 0.045369546582 * get<x24>(states) - 18.580601832107 * get<x25>(states) - 0.295436370828 * get<x26>(states) - 0.680521274763 * get<x27>(states) - 0.683600561672 * get<x28>(states)); }
    //  x17
    , [&](const auto& states){ return get<x17>(states) + dt * (-0.013549327978   * get<x6>(states) - 0.012135188033  * get<x7>(states) + 0.226991094595   * get<x8>(states)); }
    //  x18
    , [&](const auto& states){ return get<x18>(states) + dt * (-11.385989897412  * get<x1>(states)); }
    //  x19
    , [&](const auto& states){ return get<x19>(states) + dt * (-4.554395958965   * get<x2>(states)); }
    //  x20
    , [&](const auto& states){ return get<x20>(states) + dt * ( 0.243569095885   * get<x4>(states) - 4.554395958965  * get<x5>(states)); }
    //  x21
    , [&](const auto& states){ return get<x21>(states) + dt * (-4.554395958965   * get<x3>(states) - 8.500000000000  * get<x21>(states) - 18.000000000000 * get<x22>(states)); }
    //  x22
    , [&](const auto& states){ return get<x22>(states) + dt * ( 1.000000000000   * get<x21>(states)); }
    //  x23
    , [&](const auto& states){ return get<x23>(states) + dt * (-11.385989897412  * get<x4>(states) - 8.500000000000  * get<x23>(states) - 18.000000000000 * get<x24>(states)); }
    //  x24
    , [&](const auto& states){ return get<x24>(states) + dt * ( 1.000000000000   * get<x23>(states)); }
    //  x25
    , [&](const auto& states){ return get<x25>(states) + dt * ( 0.683186075980   * get<x9>(states) + 0.514736886625  * get<x10>(states) + 0.282998565164  * get<x11>(states) + 0.440668616363  * get<x12>(states) - 2.382738811465  * get<x13>(states) - 0.037424700426 * get<x14>(states) - 0.035002491999 * get<x15>(states) + 0.614952694278  * get<x16>(states) + 14.829958398888 * get<x17>(states) - 0.110759742503  * get<x18>(states) - 0.226034186438  * get<x19>(states) + 4.345468653096  * get<x20>(states) + 0.001333027828 * get<x21>(states) + 0.016376955559 * get<x22>(states) - 0.010465240818 * get<x23>(states) - 0.009422482600 * get<x24>(states) - 6.145615181050 * get<x25>(states) + 0.061014181775 * get<x26>(states) + 0.141165339638 * get<x27>(states) + 0.141806743312 * get<x28>(states)); }
    //  x26
    , [&](const auto& states){ return get<x26>(states) + dt * (-36.039354729710  * get<x9>(states) + 0.767400874818  * get<x10>(states) - 0.190879388177  * get<x11>(states) - 11.678174370212 * get<x12>(states) - 0.041149877278  * get<x13>(states) - 0.026017271417 * get<x14>(states) - 0.026698725144 * get<x15>(states) + 0.036415219598  * get<x16>(states) + 0.738656358350  * get<x17>(states) + 6.810845841283  * get<x18>(states) - 0.384784957980  * get<x19>(states) - 0.708557300741  * get<x20>(states) - 0.005524328707 * get<x21>(states) + 0.002522572903 * get<x22>(states) + 0.171826920583 * get<x23>(states) + 0.138368426838 * get<x24>(states) + 0.071909684799 * get<x25>(states) - 6.567495145681 * get<x26>(states) + 0.039293511274 * get<x27>(states) + 0.006041152866 * get<x28>(states)); }
    //  x27
    , [&](const auto& states){ return get<x27>(states) + dt * ( 1.997224587333   * get<x9>(states) + 13.482210983798 * get<x10>(states) + 2.488520358003  * get<x11>(states) + 0.076750797248  * get<x12>(states) + 0.804972334222  * get<x13>(states) + 0.023466195202 * get<x14>(states) - 0.022740687251 * get<x15>(states) + 0.018646161041  * get<x16>(states) + 0.436604617107  * get<x17>(states) - 0.414374632569  * get<x18>(states) - 6.563020897889  * get<x19>(states) - 1.423460802051  * get<x20>(states) - 0.224998971426 * get<x21>(states) - 0.259852011779 * get<x22>(states) - 0.008437464875 * get<x23>(states) - 0.003945344110 * get<x24>(states) + 0.102235829031 * get<x25>(states) + 0.191829027845 * get<x26>(states) - 6.312428841540 * get<x27>(states) - 0.038075090345 * get<x28>(states)); }
    //  x28
    , [&](const auto& states){ return get<x28>(states) + dt * ( 1.761524247668   * get<x9>(states) - 3.415298165208  * get<x10>(states) - 1.836225244248  * get<x11>(states) - 0.015605131825  * get<x12>(states) + 10.486845595600 * get<x13>(states) - 0.031379180918 * get<x14>(states) + 0.001266746410 * get<x15>(states) + 0.525873993847  * get<x16>(states) + 9.808565668907  * get<x17>(states) - 0.367529750255  * get<x18>(states) + 1.370405524130  * get<x19>(states) - 12.076970057329 * get<x20>(states) + 0.004883176776 * get<x21>(states) - 0.015765473705 * get<x22>(states) - 0.000399777933 * get<x23>(states) - 0.000497333312 * get<x24>(states) + 0.199818976539 * get<x25>(states) - 0.002648145523 * get<x26>(states) - 0.101212258081 * get<x27>(states) - 5.199268943788 * get<x28>(states)); }
    //  t
    , [&](const auto& states){ return get<t>(states)   + dt * ( 1); }
    );

  auto new_state = transform_state(trans, init_state);

  cout << get<0>(new_state);
}
