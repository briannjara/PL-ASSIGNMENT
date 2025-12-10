program LinkedListDemo;

type
  PNode = ^TNode;
  TNode = record
    data: Integer;
    next: PNode;
  end;

procedure CreateList(var head: PNode);
begin
  head := nil;
end;

procedure Insert(var head: PNode; val: Integer);
var
  node, cur: PNode;
begin
  New(node);
  node^.data := val;
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

function Delete(var head: PNode; val: Integer): Boolean;
var
  cur, prev: PNode;
begin
  cur := head;
  prev := nil;
  while cur <> nil do
  begin
    if cur^.data = val then
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
  Delete := False;
end;

procedure Traverse(head: PNode);
var
  cur: PNode;
  first: Boolean;
begin
  Write('[');
  cur := head;
  first := True;
  while cur <> nil do
  begin
    if not first then Write(', ');
    Write(cur^.data);
    first := False;
    cur := cur^.next;
  end;
  Writeln(']');
end;

var
  head: PNode;

begin
  CreateList(head);
  Insert(head, 1);
  Insert(head, 2);
  Insert(head, 3);
  Write('After create: ');
  Traverse(head);
  Insert(head, 4);
  Write('After insert 4: ');
  Traverse(head);
  if Delete(head, 2) then
    Writeln('Deleted 2: yes')
  else
    Writeln('Deleted 2: no');
  Write('Final list: ');
  Traverse(head);
end.
