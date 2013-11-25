//
//  SFMixedDataSource.m
//  Congress
//
//  Created by Daniel Cloud on 11/25/13.
//  Copyright (c) 2013 Sunlight Foundation. All rights reserved.
//

#import "SFMixedDataSource.h"
#import "SFBill.h"
#import "SFLegislator.h"

@implementation SFMixedDataSource

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (indexPath == nil) return nil;

    id object = [self itemForIndexPath:indexPath];

    Class objectClass = [object class];
    NSValueTransformer *valueTransformer;
    if (objectClass == [SFBill class]) {
        valueTransformer = [NSValueTransformer valueTransformerForName:SFDefaultBillCellTransformerName];
    }
    else if (objectClass == [SFLegislator class])
    {
        valueTransformer = [NSValueTransformer valueTransformerForName:SFDefaultLegislatorCellTransformerName];
    }
    SFCellData *cellData = [valueTransformer transformedValue:object];

    SFTableCell *cell = (SFTableCell *)[super tableView:tableView cellForRowAtIndexPath:indexPath];

    [cell setCellData:cellData];
    if (cellData.persist && [cell respondsToSelector:@selector(setPersistStyle)]) {
        [cell performSelector:@selector(setPersistStyle)];
    }
    CGFloat cellHeight = [cellData heightForWidth:tableView.width];
    [cell setFrame:CGRectMake(0, 0, cell.width, cellHeight)];

    return cell;
}

@end
