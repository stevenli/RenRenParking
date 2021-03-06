//
//  PPMapView.h
//  PigParking
//
//  Created by VincentLi on 14-7-5.
//  Copyright (c) 2014年 VincentStation. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PPMapAnnoation.h"

typedef enum {
    PPMapViewscopeModeFollow,
    PPMapViewscopeModeBrowser,
    PPMapViewscopeModeDirect
}PPMapViewscopeMode;

@class PPMapAnnoation;

@interface PPMapView : UIView  <CLLocationManagerDelegate,BMKMapViewDelegate,BMKRouteSearchDelegate>

@property (nonatomic, assign) id delegate;
@property (nonatomic, readonly) BMKMapView *mapView;
@property (nonatomic, readonly) BMKMapView *tempMapView; //for calculator region only!
@property (nonatomic, assign) PPMapViewscopeMode scopeMode;
@property (nonatomic, readonly) CLLocationCoordinate2D currentCoordinate;
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;
@property (nonatomic, readonly, copy) NSString *city;

+ (PPMapView *)sharedInstance;

+ (PPMapView *)mapViewWithFrame:(CGRect)frame;

+ (void)navigateFrom:(CLLocationCoordinate2D)from to:(CLLocationCoordinate2D)to;

- (void)clear;

- (void)startUpdatingLocation;

- (void)updateUserLocation:(CLLocationCoordinate2D)coordinate;

- (void)showAroundParking:(NSArray *)list;

- (void)showAroundServicePlace:(NSArray *)list;

- (void)zoomIn;

- (void)zoomOut;

- (void)doGeoSearch:(CLLocationCoordinate2D)location;

- (BOOL)isInPolygon:(CLLocationCoordinate2D *)coordinates forCoordinate:(CLLocationCoordinate2D)coordinate count:(NSInteger)count;

@end

@protocol PPMapViewDelegate <NSObject>

@optional
- (void)ppMapView:(PPMapView *)mapView didUpdateToLocation:(CLLocation *)newLocation;

- (void)ppMapView:(PPMapView *)mapView didSelectAnnotation:(PPMapAnnoation *)annotation;

- (void)ppMapView:(PPMapView *)mapView didDeselectAnnotation:(PPMapAnnoation *)annotation;

- (void)ppMapvViewRegionWillChange:(PPMapView *)mapView;

- (void)ppMapViewRegionDidChange:(PPMapView *)mapView;

- (void)ppMapView:(PPMapView *)mapView onGetReverseGeoCodeAddress:(NSString *)address;

@end
