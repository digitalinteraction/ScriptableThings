# Implementing Captive Portals on Ardiunos

## Definition

A Captive Portal is a WiFi network that captures the user's attention by
directing them to a website, rather than connecting directly to the internet.

## Background

The standard example Captive works by broadcasting an SSID and running a DHCP, DNS & HTTP server.
The DHCP server assigns clients an IP address and tells them to use the local DNS server.
The DNS server only ever returns the router's IP address for any request,
which traditionally prompts a device that this is a captive portal.
Devices will bring up a browser and visit that page, which is served by the HTTP server.

Usually, [something like this](https://github.com/me-no-dev/ESPAsyncWebServer/blob/master/examples/CaptivePortal/CaptivePortal.ino)

## Problems

As of 2025, this method is no longer reliable on Android.
Captive Portals have also moved on with new specifications:

- [RFC 7710](https://datatracker.ietf.org/doc/html/rfc7710)
- [RFC 8908](https://datatracker.ietf.org/doc/html/rfc8908)
- [RFC 8910](https://datatracker.ietf.org/doc/html/rfc8910) which superceeds `7710`

The path forwards seems to be to use the DHCP option 114 to tell clients about the captive portal,
rather then using the DNS-hack. This method needs a configurable DHCP server that lets you set this option.
This DHCP server doesn't seem to exist yet.

The Arduino DHCP server is not available to developers and doesn't let you configure how it works.

> It might be worth investigating this [DHCP library](https://github.com/pkulchenko/DHCPLite)

## Investigation

- [Reddit thread describing option 114](https://www.reddit.com/r/esp32/comments/1h387rp/captive_portal_doesnt_show_pop_up/)
- [And another](https://www.reddit.com/r/networking/comments/t4webr/push_captive_portal_after_wifi_association/)
- A [very relevant GitHub issue](https://github.com/platformio/platform-espressif32/issues/1519) which I can't find any follow up or conencted issue in the `espressif/arduino-esp32` repository
- [Somewhat relevant issue about implementing DHCP over ethernet](https://github.com/espressif/esp-idf/issues/8886)

From scanning the source code, it seems esp-idf doesn’t expose a way to configure which DHCP options to get/set, so re-compiling that might be necessary.

- This isn’t the best direction either as it bakes in the requirement for using esp-idf rather than just Arduino
- The ideal option would be to propose an update to the Arduino WiFi standard that configures

- A [similar request](https://github.com/esp8266/Arduino/issues/1956) for setting DHCP options in the Arduino wifi library
- [An old guide for creating a captive portal](https://iotespresso.com/create-captive-portal-using-esp32/)
