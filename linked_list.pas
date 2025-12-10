program LinkedListDemo;

type
  PNode = ^TNode;
  TNode = record
    title: string;
    author: string;
    rating: Real;
    next: PNode;
  end;

procedure CreateList(var head: PNode);
begin
  head := nil;
end;

procedure InsertBook(var head: PNode; t, a: string; r: Real);
var
  node, cur: PNode;
begin
  New(node);
  node^.title := t;
  node^.author := a;
  node^.rating := r;
  node^.next := nil;
  if head = nil then
    head := node
  else
  begin
    cur := head;
    while cur^.next <> nil do
      cur := cur^.next;
    cur^.next := node;
  end;
end;

function DeleteBook(var head: PNode; t: string): Boolean;
var
  cur, prev: PNode;
begin
  cur := head;
  prev := nil;
  while cur <> nil do
  begin
    if cur^.title = t then
    begin
      if prev = nil then
        head := cur^.next
      else
        prev^.next := cur^.next;
      Dispose(cur);
      Exit(True);
    end;
    prev := cur;
    cur := cur^.next;
  end;
  DeleteBook := False;
end;

procedure TraverseBooks(head: PNode);
var
  cur: PNode;
  i: Integer;
begin
  cur := head;
  i := 1;
  if cur = nil then
  begin
    Writeln('(no books in the list)');
    Exit;
  end;
  while cur <> nil do
  begin
    Write(i); Write('. '); Write(cur^.title); Write(' by '); Write(cur^.author); Write(' - Rating: ');
    Write(cur^.rating:0:1);
    Writeln;
    cur := cur^.next;
    i := i + 1;
  end;
end;

var
  head: PNode;

begin
  CreateList(head);

  { sample books }
  InsertBook(head, 'The Hobbit', 'J.R.R. Tolkien', 4.8);
  InsertBook(head, '1984', 'George Orwell', 4.6);
  InsertBook(head, 'To Kill a Mockingbird', 'Harper Lee', 4.7);

  Writeln('Books after create:');
  TraverseBooks(head);

  InsertBook(head, 'Dune', 'Frank Herbert', 4.5);
  Writeln;
  Writeln('After inserting ''Dune'':');
  TraverseBooks(head);

  if DeleteBook(head, '1984') then
    Writeln;
    Writeln('Deleted ''1984'': yes')
  else
    Writeln('Deleted ''1984'': no');

  Writeln;
  Writeln('Final list:');
  TraverseBooks(head);
end.
