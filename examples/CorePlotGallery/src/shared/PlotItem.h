//
//  PlotItem.h
//  CorePlotGallery
//
//  Created by Jeff Buck on 8/31/10.
//  Copyright 2010 Jeff Buck. All rights reserved.
//

#import <Foundation/Foundation.h>

#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
#import "CorePlot-CocoaTouch.h"
#import <UIKit/UIKit.h>

typedef CGRect CGNSRect;

#else

#import <CorePlot/CorePlot.h>
typedef NSRect CGNSRect;
#endif

extern NSString *const kDemoPlots;
extern NSString *const kPieCharts;
extern NSString *const kLinePlots;
extern NSString *const kBarPlots;
extern NSString *const kFinancialPlots;

@class CPTGraph;
@class CPTTheme;

@interface PlotItem : NSObject

@property (nonatomic, readwrite, strong) CPTGraphHostingView *defaultLayerHostingView;

@property (nonatomic, readwrite, strong) NSMutableArray *graphs;
@property (nonatomic, readwrite, strong) NSString *section;
@property (nonatomic, readwrite, strong) NSString *title;

+(void)registerPlotItem:(id)item;

#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
-(void)renderInView:(UIView *)hostingView withTheme:(CPTTheme *)theme animated:(BOOL)animated;
#else
-(void)renderInView:(NSView *)hostingView withTheme:(CPTTheme *)theme animated:(BOOL)animated;
-(void)setFrameSize:(NSSize)size;
#endif
-(CPTNativeImage *)image;

-(void)renderInLayer:(CPTGraphHostingView *)layerHostingView withTheme:(CPTTheme *)theme animated:(BOOL)animated;

-(void)setTitleDefaultsForGraph:(CPTGraph *)graph withBounds:(CGRect)bounds;
-(void)setPaddingDefaultsForGraph:(CPTGraph *)graph withBounds:(CGRect)bounds;

-(void)reloadData;
-(void)applyTheme:(CPTTheme *)theme toGraph:(CPTGraph *)graph withDefault:(CPTTheme *)defaultTheme;

-(void)addGraph:(CPTGraph *)graph;
-(void)addGraph:(CPTGraph *)graph toHostingView:(CPTGraphHostingView *)layerHostingView;
-(void)killGraph;

-(void)generateData;

-(NSComparisonResult)titleCompare:(PlotItem *)other;

@end
