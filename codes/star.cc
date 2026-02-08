#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/internet-module.h"
#include "ns3/netanim-module.h"
#include "ns3/mobility-module.h"

using namespace ns3;

int main ()
{
    NodeContainer hub;
    hub.Create (1);

    NodeContainer spokes;
    spokes.Create (15);

    InternetStackHelper internet;
    internet.Install (hub);
    internet.Install (spokes);

    PointToPointHelper p2p;
    p2p.SetDeviceAttribute ("DataRate", StringValue ("10Mbps"));
    p2p.SetChannelAttribute ("Delay", StringValue ("2ms"));

    for (uint32_t i = 0; i < spokes.GetN (); i++)
    {
        p2p.Install (hub.Get (0), spokes.Get (i));
    }

    MobilityHelper mobility;
    mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
    mobility.Install (hub);
    mobility.Install (spokes);

    hub.Get (0)->GetObject<MobilityModel> ()
        ->SetPosition (Vector (200, 200, 0));

    for (uint32_t i = 0; i < spokes.GetN (); i++)
    {
        double angle = (2 * M_PI / spokes.GetN ()) * i;
        double x = 200 + 120 * cos (angle);
        double y = 200 + 120 * sin (angle);
        spokes.Get (i)->GetObject<MobilityModel> ()
            ->SetPosition (Vector (x, y, 0));
    }

    AnimationInterface anim ("24bce1619_star.xml");

    Simulator::Run ();
    Simulator::Destroy ();
    return 0;
}
