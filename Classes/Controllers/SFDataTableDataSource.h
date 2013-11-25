//
//  SFDataTableDataSource.h
//  Congress
//
//  Created by Daniel Cloud on 11/25/13.
//  Copyright (c) 2013 Sunlight Foundation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SFTableCell.h"
#import "SFCellData.h"

typedef NSUInteger (^SFDataTableSortIntoSectionsBlock)(id obj, NSArray *sectionTitles);
typedef NSArray* (^SFDataTableSectionTitleGenerator)(NSArray *items);
typedef NSArray* (^SFDataTableSectionIndexTitleGenerator)(NSArray *sectionTitles);
typedef NSInteger (^SFDataTableSectionForSectionIndexHandler)(NSString *title, NSInteger index, NSArray *sectionTitles);
typedef NSArray* (^SFDataTableOrderItemsInSectionsBlock)(NSArray *sectionItems);
typedef id (^SFDataTableCellForIndexPathHandler)(NSIndexPath *indexPath);

@interface SFDataTableDataSource : NSObject <UITableViewDataSource>

@property (strong, nonatomic) NSArray *items;
@property (strong, nonatomic) NSArray *sections;
@property (strong, nonatomic) NSArray *sectionTitles;
@property (strong, nonatomic) NSArray *sectionIndexTitles;

@property (readwrite, copy) SFDataTableSortIntoSectionsBlock sortIntoSectionsBlock;
@property (readwrite, copy) SFDataTableOrderItemsInSectionsBlock orderItemsInSectionsBlock;
@property (readwrite, copy) SFDataTableSectionTitleGenerator sectionTitleGenerator;
@property (readwrite, copy) SFDataTableCellForIndexPathHandler cellForIndexPathHandler;
@property (readwrite, copy) SFDataTableSectionIndexTitleGenerator sectionIndexTitleGenerator;
@property (readwrite, copy) SFDataTableSectionForSectionIndexHandler sectionIndexHandler;

- (void)setSectionTitleGenerator:(SFDataTableSectionTitleGenerator)pSectionTitleGenerator
                sortIntoSections:(SFDataTableSortIntoSectionsBlock)pSectionSorter
            orderItemsInSections:(SFDataTableOrderItemsInSectionsBlock)pOrderItemsInSectionsBlock
         cellForIndexPathHandler:(SFDataTableCellForIndexPathHandler)pCellForIndexPathHandler;

- (void)setSectionIndexTitleGenerator:(SFDataTableSectionIndexTitleGenerator)pSectionIndexTitleGenerator
                  sectionIndexHandler:(SFDataTableSectionForSectionIndexHandler)pSectionForSectionIndexHandler;

- (void)sortItemsIntoSections;

- (id)itemForIndexPath:(NSIndexPath *)indexPath;

@end
