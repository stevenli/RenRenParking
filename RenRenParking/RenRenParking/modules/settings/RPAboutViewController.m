//
//  RPAboutViewController.m
//  RenRenParking
//
//  Created by LiYongQiang on 14/10/22.
//  Copyright (c) 2014年 CoderFly. All rights reserved.
//

#import "RPAboutViewController.h"

@interface RPAboutViewController ()

@end

@implementation RPAboutViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self)
    {
        self.title = NSLocalizedString(@"关于我们", nil);
        self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithBarButtonThemeItem:UIBarButtonThemeItemBack target:self action:@selector(btnBackClick)];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [self setupTheme];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark -

- (void)btnBackClick
{
    [self.navigationController popViewControllerAnimated:YES];
}

@end
